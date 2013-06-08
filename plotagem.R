dataframe = read.table("dadoscap.txt", skip=1, header=FALSE)
curve(8.805545*exp(-0.022771*x), from=0, to=155, xlab="Tempo (segundos)", ylab="Tensão (volts)")
points(dataframe)