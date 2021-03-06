/*
 * Copyright (c) 2013 Yannik Li(Yanqing Li)
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __ARCH_H__
#define __ARCH_H__

/*
 * On ARMv5 and above those functions can be implemented around the
 * clz instruction for much better code efficiency.  __clz returns
 * the number of leading zeros, zero input will return 32, and
 * 0x80000000 will return 0.
 */
static inline unsigned int __clz(unsigned int x)
{
	unsigned int ret;

	asm("clz\t%0, %1" : "=r" (ret) : "r" (x));

	return ret;
}

/*
 * fls() returns zero if the input is zero, otherwise returns the bit
 * position of the last set bit, where the LSB is 1 and MSB is 32.
 */
static inline int fls(int x)
{
	return 32 - __clz(x);
}

void exception_init(void);
void arch_early_init(void);

#endif
