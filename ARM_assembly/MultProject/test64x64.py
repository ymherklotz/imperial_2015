#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      tomcl
#
# Created:     11/12/2015
# Copyright:   (c) tomcl 2015
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import random

def rand64():
    bits = random.getrandbits(64) # 64 random bits, us unsigned
    if bits >= (1<<63):   # convert from unsigned to signed representation
        return bits - (1<<64)
    else:
        return bits

def twosComp(x,width=128): # comvert from signed int to two's comp representation
                           # choose large default width, when extracting lower bits
                           # too large a value of width does not matter
    if x < 0:
        return (1 << width) + x
    else:
        return x

def pw(x):
    return "0X%X" % (x % (1<<32))

def pw0(x):
    return pw(twosComp(x))

def pw1(x):
    return pw (twosComp(x) >> 32)

def pw2(x):
    return pw (twosComp(x) >> 64)

def pw3(x):
    return pw (twosComp(x) >> 96)

def makeData(name, num, dat, s=""):
    return ("%s%s%d DCD %s\n"% (("\n ; " + s + "\n" if s else ""), name, num, ",".join(dat)))

def genTest(num, a,b, s):
    p = a*b # this is the correct 128 bit product of a and b
    s = makeData("INA",num, [pw0(a), pw1(a)], s)
    s += makeData("INB", num, [pw0(b),pw1(b)])
    s += makeData("OUTAxB", num, [pw0(p),pw1(p),pw2(p),pw3(p)])
    return s

def makeTestData():
    s = genTest(0, 0x200000030, 0x50000007000, "Test 0: simple diagnostic")
    s += genTest(1,0x7FFFFFFF, 0x7FFFFFFF, "Test 1: carries" )
    s += genTest(2, 0, 0, "Test 2: all zeros")
    s += genTest(3, -1, -1, "Test 3: both negative")
    s += genTest(4, -1, 1, "Test 4: A negative")
    s += genTest(5, 1, -1, "Test 5: B negative")
    s += genTest(6, rand64(), rand64(), "Test 6: Random bits")
    s += genTest(7, rand64(), rand64(), "Test 7: Random bits")
    return s

print makeTestData()
