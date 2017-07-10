# adapted from linux-imx.inc, copyright (C) 2012-2014 O.S. Systems Software LTDA
# Released under the MIT license (see COPYING.MIT for the terms)

include linux-udooboard.inc
require recipes-kernel/linux/linux-dtb.inc

SRCREV = "c460cad2f35c9e8d1d567db631ffead68057566d"

# This hack is needed because of the
# backports subdir in the kernel source
B = "${S}"

COMPATIBLE_MACHINE = "(udooneo|udooqdl|secosbca62)"
