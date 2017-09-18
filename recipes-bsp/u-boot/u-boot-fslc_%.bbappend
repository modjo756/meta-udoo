FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

COMPATIBLE_MACHINE = "(udooqdl|udooneo|secosbca62)"

SRC_URI += " \
            file://0001-UDOO-Quad-Dual-support.patch \
            file://0002-UDOO-Neo-support.patch \
            file://0003-Removed-dts-folder-from-device-tree-file-name.patch \
            file://0004-Added-Seco-A62-support.patch \
            file://0005-u-boot-neo-Add-PXE-to-UDOO-Neo.patch \
            file://0006-u-boot-fslc-Set-default-environment-variables-for-PX.patch \
"
