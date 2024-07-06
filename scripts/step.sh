root <<EOF
.L analyseSteps.C
analyseSteps("MCStepLoggerOutput.root")
EOF

root <<EOF
.L stepStudy.cxx
stepStudy("metal")
stepStudy("sensor")
stepStudy("chip")
EOF

root <<EOF
.x stepPlot.C
EOF