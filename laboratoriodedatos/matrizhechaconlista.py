matriz = []
grande = []
contador = 0
fila = int(input("inserte numero de filas "))
columna = int(input("inserte numero de columnas "))

for f in range(fila):
    filist = []
    for c in range(columna):
        print("inserte el numero de votos para la ciudad", f+1, "para el candidato", c+1, "\n")
        filist.append(int(input()))
    matriz.append(filist)

for f in range(fila):
    for c in range(columna):
        print("ciudad", f+1, "candidato", c+1, matriz[f][c], end=" ")
    print()

for f in range(fila):
    sum=0
    for c in range(columna):

        sum+=matriz[c][f]
        grande.append(sum)
    print("la suma total de votos por el candidato", f, "fueron de:", sum, "\n")
for f in range(fila):
    sum=0
    for c in range(columna):
        sum+=matriz[f][c]
        grande.append(sum)
    print("la suma total de en la ciudad", f, "fueron de:", sum, "\n")

alo = grande.index(max(grande))
print("gano el candidato", alo, "con una cantidad de:", max(grande), "votos! \n") 
