/*
 The MIT License (MIT)

 Copyright (c) 2017 HJC hjcapple@gmail.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef __CF_SCOPERELEASE_H__
#define __CF_SCOPERELEASE_H__

#include <CoreFoundation/CFBase.h>

#define __CF_SCOPE_CONCATENATE_IMPL(s1, s2) s1##s2
#define __CF_SCOPE_CONCATENATE(s1, s2) __CF_SCOPE_CONCATENATE_IMPL(s1, s2)

static inline void CF_SafeRelease(CFTypeRef ref)
{
    if (ref)
    {
        CFRelease(ref);
    }
}

static inline void CF_SafeRetain(CFTypeRef ref)
{
    if (ref)
    {
        CFRetain(ref);
    }
}

inline static void CF_ExecuteCleanup(CFTypeRef* pref)
{
    CF_SafeRelease(*pref);
}

#define CF_SCOPE_RELEASE(ref) \
    CFTypeRef __CF_SCOPE_CONCATENATE(RELEASE, __LINE__) __attribute__((cleanup(CF_ExecuteCleanup), unused)) = ref;

#endif
