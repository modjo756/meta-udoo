# Adapted from linux-imx.inc, copyright (C) 2012, 2013 O.S. Systems Software LTDA
# Released under the MIT license (see COPYING.MIT for the terms)

SUMMARY = "Linux kernel for UDOO boards"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

require recipes-kernel/linux/linux-imx.inc

DEPENDS += "lzop-native bc-native"

# Put a local version until we have a true SRCREV to point to
SCMVERSION ?= "y"

# UDOOboard branch - based on 3.14-1.0.x-udoo from Freescale git
SRCBRANCH = "3.14-1.0.x-udoo"
LOCALVERSION = "_1.0.x-udoo"

# Allow override of UDOOBOARD_GITHUB_MIRROR to make use of
# local repository easier
UDOOBOARD_GITHUB_MIRROR ?= "git://github.com/UDOOboard/linux_kernel.git"

# SRC_URI for udoo boards kernel
SRC_URI = "${UDOOBOARD_GITHUB_MIRROR};branch=${SRCBRANCH} \
           file://0001-ARM-8158-1-LLVMLinux-use-static-inline-in-ARM-ftrace.patch \
           file://0002-ARM-LLVMLinux-Change-extern-inline-to-static-inline-.patch \
           file://0003-avoid-endless-loop.patch \
           file://0005-add-support-for-gcc6.patch \
           file://defconfig \
"
SRC_URI_append_udooqdl = "file://001-lvds15_changeConfTo10.patch \
           file://0006-add-support-goodix-touchscreen.patch \
"

SRC_URI_append_udooneo = " \
    ${@base_conditional("ENABLE_CAN_BUS", "1", "file://0001-Enable-FlexCAN-interfaces-for-UDOO-Neo.patch", "", d)} \
    ${@base_conditional("ENABLE_SPI_BUS", "1", "file://0020-udooneo-enable-ecspi2.patch", "", d)} \
    ${@base_conditional("ENABLE_UART6", "1", "file://0021-Enable-Uart6-udooneo.patch", "", d)} \
    ${@base_conditional("ENABLE_UART6", "1", "file://0022-udooneo-Uart6-dma.patch", "", d)} \
"
SRC_URI_append_secosbca62 = "file://0001-enable-eth-SA62.patch \
           file://0002-add_external_clock-SA62.patch \
           file://0003-add_FrameBuffer-2-3-SA62.patch \
           file://0004-add_CAN-SA62.patch \
           file://0005-add_SPI-SA62.patch \
           file://0006-add_I2C-SA62.patch \
           file://0007-add_UART5-SA62.patch \
           file://0008-lvds15_changeConf_SA62.patch \
           ${@base_conditional("ENABLE_TOUCH_GOODIX", "1","file://0009-support-Goodix-Touchscreens.patch", "", d)} \
"