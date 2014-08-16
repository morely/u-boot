/*
 * Copyright (C) 2012 Freescale Semiconductor, Inc.
 *
 * Configuration settings for the Freescale i.MX6Q SabreSD board.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __MX6Q_E9_CONFIG_H
#define __MX6Q_E9_CONFIG_H

#include <asm/arch/imx-regs.h>
#include <asm/imx-common/gpio.h>
#include "mx6_common.h"
#include <linux/sizes.h>

#define CONFIG_MACH_TYPE	3980
#define CONFIG_MXC_UART_BASE	UART1_BASE
#define CONFIG_CONSOLE_DEV		"ttymxc0"
#define CONFIG_MMCROOT			"/dev/mmcblk0p1"
#define PHYS_SDRAM_SIZE		(2u * 1024 * 1024 * 1024)

#define CONFIG_SUPPORT_EMMC_BOOT /* eMMC specific */

#define CONFIG_MX6

#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

#define CONFIG_SYS_GENERIC_BOARD

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * SZ_1M)

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_MXC_GPIO

#define CONFIG_MXC_UART

#define CONFIG_CMD_FUSE
#ifdef CONFIG_CMD_FUSE
#define CONFIG_MXC_OCOTP
#endif

/* MMC Configs */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR      0

#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_FS_FAT
#define CONFIG_FS_EXT4
#define CONFIG_CMD_FS_GENERIC			/* Generic load commands */
#define CONFIG_CMD_BOOTZ			/* bootz zImage support */
#define CONFIG_SUPPORT_RAW_INITRD		/* bootz raw initrd support */
#define CONFIG_GENERIC_MMC
#define CONFIG_BOUNCE_BUFFER
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_FAT
#define CONFIG_DOS_PARTITION

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII
#define CONFIG_CMD_NET
#define CONFIG_FEC_MXC
#define CONFIG_MII
#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_XCV_TYPE		RGMII
#define CONFIG_ETHPRIME			"FEC"
#define CONFIG_FEC_MXC_PHYADDR		5
#define CONFIG_PHYLIB
#define CONFIG_PHY_REALTEK

#define CONFIG_CMD_SF
#ifdef CONFIG_CMD_SF
#define CONFIG_SPI_FLASH
#define CONFIG_SPI_FLASH_STMICRO
#define CONFIG_MXC_SPI
#define CONFIG_SF_DEFAULT_BUS		0
#define CONFIG_SF_DEFAULT_CS		(0 | (IMX_GPIO_NR(4, 9) << 8))
#define CONFIG_SF_DEFAULT_SPEED		20000000
#define CONFIG_SF_DEFAULT_MODE		SPI_MODE_0
#endif

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_CONS_INDEX              	1
#define CONFIG_BAUDRATE                	115200

/* Command definition */
#include <config_cmd_default.h>

#define CONFIG_CMD_BMODE
#define CONFIG_CMD_BOOTZ
#define CONFIG_CMD_SETEXPR
#undef CONFIG_CMD_IMLS

#define CONFIG_BOOTDELAY               	1

#define CONFIG_LOADADDR               	0x12000000
#define CONFIG_SYS_TEXT_BASE           	0x17800000

#define CONFIG_ARP_TIMEOUT   		200UL

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT	"uboot> "
//#define CONFIG_SYS_PROMPT_HUSH_PS2     "> "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE              256

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS             16
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE

#define CONFIG_SYS_MEMTEST_START       0x10000000
#define CONFIG_SYS_MEMTEST_END         0x10010000
#define CONFIG_SYS_MEMTEST_SCRATCH     0x10800000

#define CONFIG_SYS_LOAD_ADDR           CONFIG_LOADADDR

#define CONFIG_CMDLINE_EDITING
#define CONFIG_STACKSIZE               (128 * 1024)

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS           1
#define PHYS_SDRAM                     MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE          PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR       IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE       IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_ENV_SIZE			(8 * 1024)

#define CONFIG_ENV_IS_IN_MMC

#if defined(CONFIG_ENV_IS_IN_MMC)
#define CONFIG_ENV_OFFSET		(6 * 64 * 1024)
#endif

#define CONFIG_OF_LIBFDT

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

#define CONFIG_SYS_FSL_USDHC_NUM	3
#if defined(CONFIG_ENV_IS_IN_MMC)
#define CONFIG_SYS_MMC_ENV_DEV		2	/* SDHC4 */
#endif

/* Framebuffer */
#define CONFIG_VIDEO
#define CONFIG_VIDEO_IPUV3
#define CONFIG_CFB_CONSOLE
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_SPLASH_SCREEN_ALIGN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_VIDEO_BMP_LOGO
#define CONFIG_IPUV3_CLK 260000000
#define CONFIG_IMX_HDMI
#define CONFIG_IMX_VIDEO_SKIP

#define CONFIG_CMD_PCI
#ifdef CONFIG_CMD_PCI
#define CONFIG_PCI
#define CONFIG_PCI_PNP
#define CONFIG_PCI_SCAN_SHOW
#define CONFIG_PCIE_IMX
#define CONFIG_PCIE_IMX_PERST_GPIO	IMX_GPIO_NR(7, 12)
#define CONFIG_PCIE_IMX_POWER_GPIO	IMX_GPIO_NR(3, 19)
#endif

/* I2C Configs */
#define CONFIG_CMD_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC
#define CONFIG_SYS_I2C_SPEED		  100000

#ifdef CONFIG_SUPPORT_EMMC_BOOT
#define EMMC_ENV \
	"emmcdev=2\0" \
	"update_emmc_firmware=" \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"if ${get_cmd} ${update_sd_firmware_filename}; then " \
			"if mmc dev ${emmcdev} && " \
				"mmc open ${emmcdev} 1; then "	\
				"setexpr fw_sz ${filesize} / 0x200; " \
				"setexpr fw_sz ${fw_sz} + 1; "	\
				"mmc write ${loadaddr} 0x2 ${fw_sz}; " \
				"mmc close ${emmcdev} 1; " \
			"fi; "	\
		"fi\0"
#else
#define EMMC_ENV ""
#endif

#define CONFIG_EXTRA_ENV_SETTINGS \
	"script=boot.scr\0" \
	"console=" CONFIG_CONSOLE_DEV "\0" \
	"optargs=\0" \
	"cmdline=\0" \
	"image=zImage\0" \
	"boot_fdt=try\0" \
	"fdt_file=imx6q-e9.dtb \0" \
	"fdt_high=0xffffffff\0"\
	"fdt_addr=0x18000000\0" \
	"mmcdev=2\0" \
	"mmcpart=1\0" \
	"mmcroot=/dev/mmcblk0p${mmcpart} ro\0" \
	"mmcrootfstype=ext4 rootwait fixrtc\0" \
	"ip_dyn=no\0" \
	"netdev=eth0\0"\
	"ethaddr=12:32:43:34:21:43\0"\
	"ipaddr=192.168.1.103\0"\
	"netmask=255.255.255.0\0"\
	"serverip=192.168.1.91\0"\
	"nfsserverip=192.168.1.91\0"\
	"gatemask=192.168.1.1\0"\
	"nfsroot=/home/mitch/share/nfs/rootfs\0"\
	EMMC_ENV	  \
	"displayArgs=video=mxcfb0:dev=hdmi,1920x1080M@60,if=RGB24,bpp=32 "\
		"video=mxcfb1:off "\
		"video=mxcfb2:off "\
		"video=mxcfb3:off "\
		"fbmem=48M\0"\
	"bootargs=\0"\
	"mmcargs=setenv bootargs "\
		"console=${console},${baudrate} " \
		"${displayArgs} "\
		"root=${mmcroot} " \
		"rootfstype=${mmcrootfstype} " \
		"${cmdline}\0" \
	"nfsargs=setenv bootargs " \
		"console=${console},${baudrate} " \
		"${displayArgs} "\
		"root=/dev/nfs "\
		"ip=${ipaddr}:${nfsserverip}:${gatemask}:${netmask}:${netdev} " \
		"nfsroot=${serverip}:${nfsroot},v3,tcp\0" \
	"tf_args=setenv bootargs " \
		"console=${console},${baudrate} " \
		"${displayArgs} "\
		"root=/dev/mmcblk0p1 rootfstype=${mmcrootfstype}\0" \
	"netargs=run tf_args\0"\
	"mmc_boot=mmc dev ${mmcdev}; " \
		"run mmcargs;"\
		"if mmc rescan; then " \
			"echo SD/MMC found on device ${mmcdev};" \
			"setenv bootpart ${mmcdev}:${mmcpart}; " \
			"echo Checking for: /boot/uEnv.txt ...;" \
			"if test -e mmc ${bootpart} /boot/uEnv.txt; then " \
				"load mmc ${bootpart} ${loadaddr}  /boot/uEnv.txt;" \
				"env import -t ${loadaddr} ${filesize};" \
				"echo Loaded environment from  /boot/uEnv.txt;" \
				"echo Checking if uenvcmd is set ...;" \
				"if test -n ${uenvcmd}; then " \
					"echo Running uenvcmd ...;" \
					"run uenvcmd;" \
				"fi;" \
			"fi; " \
		"fi;\0" \
	"netboot=echo Booting from net ...; " \
		"run netargs; " \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"${get_cmd} ${image}; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if ${get_cmd} ${fdt_addr} ${fdt_file}; then " \
				"bootz ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootz; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootz; " \
		"fi;\0" \
	"mmcboot_e9=echo Booting from mmc ...; "\
		"run mmcargs;"\
		"mmc dev 2;"\
		"mmc read 0x10800000 0x800 0x3000;bootm; \0"\
	"update_sd_firmware=" \
		"if test ${ip_dyn} = yes; then " \
			"setenv get_cmd dhcp; " \
		"else " \
			"setenv get_cmd tftp; " \
		"fi; " \
		"if mmc dev ${mmcdev}; then "	\
			"if ${get_cmd} ${update_sd_firmware_filename}; then " \
				"setexpr fw_sz ${filesize} / 0x200; " \
				"setexpr fw_sz ${fw_sz} + 1; "	\
				"mmc write ${loadaddr} 0x2 ${fw_sz}; " \
			"fi; "	\
		"fi\0" \

#define CONFIG_BOOTCOMMAND \
	"run netboot;"\
	"setenv mmcdev 0;" \
	"setenv mmckernel 0;" \
	"run mmc_boot;" \
	"setenv mmcdev 2;" \
	"run mmc_boot;"

#endif                         /* __MX6Q_E9_CONFIG_H */
