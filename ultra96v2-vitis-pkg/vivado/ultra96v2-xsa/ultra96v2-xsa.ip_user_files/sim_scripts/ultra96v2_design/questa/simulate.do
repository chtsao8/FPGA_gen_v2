onbreak {quit -f}
onerror {quit -f}

vsim -lib xil_defaultlib ultra96v2_design_opt

do {wave.do}

view wave
view structure
view signals

do {ultra96v2_design.udo}

run -all

quit -force
