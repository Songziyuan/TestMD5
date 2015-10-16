/**
 * 基于c语言的md5加密
 */

#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "md5.h"

// md5加密
JNIEXPORT jstring JNICALL Java_com_example_testmd5_MainActivity_encryptByMD5(JNIEnv *env, jclass obj, jstring strText)
{
	char* szText = "admin";

	MD5_CTX context = { 0 };
	MD5_Init(&context);
	MD5_Update(&context, szText, strlen(szText));
	unsigned char dest[16] = { 0 };
	MD5_Final(dest, &context);
//	(*env)->ReleaseStringUTFChars(env, strText, szText);

	int i = 0;
	char szMd5[32] = { 0 };
	for (i = 0; i < 16; i++)
	{
		sprintf(szMd5, "%s%02x", szMd5, dest[i]);
	}

	return (*env)->NewStringUTF(env, szMd5);
}

jstring
Java_com_example_testmd5_MainActivity_getCPUArch( JNIEnv* env,
													 jobject thiz )
{
#if defined(__arm__)
	#if defined(__ARM_ARCH_7A__)
        #if defined(__ARM_NEON__)
          #if defined(__ARM_PCS_VFP)
            #define ABI "armeabi-v7a/NEON (hard-float)"
          #else
            #define ABI "armeabi-v7a/NEON"
          #endif
        #else
          #if defined(__ARM_PCS_VFP)
            #define ABI "armeabi-v7a (hard-float)"
          #else
            #define ABI "armeabi-v7a"
          #endif
        #endif
      #else
       #define ABI "armeabi"
      #endif
#elif defined(__i386__)
	#define ABI "x86"
#elif defined(__x86_64__)
	#define ABI "x86_64"
#elif defined(__mips64)  /* mips64el-* toolchain defines __mips__ too */
	#define ABI "mips64"
#elif defined(__mips__)
	#define ABI "mips"
#elif defined(__aarch64__)
#define ABI "arm64-v8a"
#else
	#define ABI "unknown"
#endif

	return (*env)->NewStringUTF(env, ABI);
}
