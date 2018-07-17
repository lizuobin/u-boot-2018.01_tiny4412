/*
 * Copyright (C) 2011 Samsung Electronics
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>
#include <asm/arch/mmc.h>
#include <asm/arch/periph.h>
#include <asm/arch/pinmux.h>
#include <usb.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <asm/arch/clock.h>

DECLARE_GLOBAL_DATA_PTR;

u32 get_board_rev(void)
{
	return 0;
}

static void board_gpio_init(void)
{
    /* dm9621 reset Pin */
    gpio_request(EXYNOS4X12_GPIO_M24, "DM9621 reset");

    gpio_cfg_pin(EXYNOS4X12_GPIO_M24, S5P_GPIO_FUNC(0x1));
    gpio_set_pull(EXYNOS4X12_GPIO_M24, S5P_GPIO_PULL_UP);
    gpio_set_value(EXYNOS4X12_GPIO_M24, 0);
    udelay(10000);
    gpio_set_value(EXYNOS4X12_GPIO_M24, 1);
}

int exynos_init(void)
{
	board_gpio_init();
	return 0;
}

int board_usb_init(int index, enum usb_init_type init)
{
	return 0;
}

#ifdef CONFIG_BOARD_EARLY_INIT_F
int exynos_early_init_f(void)
{
	return 0;
}
#endif
