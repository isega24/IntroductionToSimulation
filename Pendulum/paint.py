import matplotlib.pyplot as pyplt
import sys
infile = open(sys.argv[1], 'r')
paintingX = []
paintingY = []
for lin in infile:
    line = lin.split()
    paintingX.append(float(line[0]))
    paintingY.append(float(line[1]))
# Cerramos el fichero.

pyplt.plot(paintingX,paintingY)

pyplt.show()
infile.close()
