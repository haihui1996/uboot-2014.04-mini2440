/////////////////////////////////////////////////////////////////////////////
//@FileName:  io.c
//@Path:      .\arch\arm\cpu\arm920t\s3c24x0
//@Description:
//@Copyright (c) 2020 Haihui Deng
//@Author
/////////////////////////////////////////////////////////////////////////////
#include <common.h>
#include <asm/io.h>
#include <asm/arch/s3c24x0_cpu.h>

void __raw_writesb(unsigned int addr, const void *data, int bytelen)
{
    uint8_t *buf = (uint8_t *)data;
    while (bytelen--)
        __arch_putb(*buf++, addr);
}

void __raw_writesw(unsigned int addr, const void *data, int wordlen)
{
    uint16_t *buf = (uint16_t *)data;
    while (wordlen--)
        __arch_putw(*buf++, addr);
}

void __raw_writesl(unsigned int addr, const void *data, int longlen)
{
    uint32_t *buf = (uint32_t *)data;
    while (longlen--)
        __arch_putl(*buf++, addr);
}

void __raw_readsb(unsigned int addr, void *data, int bytelen)
{
    uint8_t *buf = (uint8_t *)data;
    while (bytelen--)
        *buf++ = __arch_getb(addr);
}

void __raw_readsw(unsigned int addr, void *data, int wordlen)
{
    uint16_t *buf = (uint16_t *)data;
    while (wordlen--)
        *buf++ = __arch_getw(addr);
}

void __raw_readsl(unsigned int addr, void *data, int longlen)
{
    uint32_t *buf = (uint32_t *)data;
    while (longlen--)
        *buf++ = __arch_getl(addr);
}
