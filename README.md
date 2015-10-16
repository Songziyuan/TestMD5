# TestMD5
This is an OpenSSL-compatible implementation of the RSA Data Security, Inc. MD5 Message-Digest Algorithm (RFC 1321).

Written by [Solar Designer <solar at openwall.com>][1] in 2001 and placed in the public domain. There's absolutely no warranty.

This differs from Colin Plumb's older public domain implementation in that no exactly 32-bit integer data type is required (any 32-bit or wider unsigned integer data type will do), there's no compile-time endianness configuration, and the function prototypes match OpenSSL's. No code from Colin Plumb's implementation has been reused; this comment merely compares the properties of the two independent implementations.

The primary goals of this implementation are portability and ease of use. It is meant to be fast, but not as fast as possible. Some known optimizations are not included to reduce source code size and avoid compile-time configuration.

Note: origin desc is [here][2],this page is just backup

[1]:http://openwall.info/wiki/people/solar
[2]:http://openwall.info/wiki/people/solar/software/public-domain-source-code/md5