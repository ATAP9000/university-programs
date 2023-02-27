empleados = {}
opcion = 0
loop = 1
while loop == 1:
    opcion = input("\nMENU: \n 1.crear \n 2.borrar \n 3.buscar \n 4.lista \n 5.fin \n")
    opcion = int(opcion)
    if opcion == 1:
            empleados[input("cedula: ")] = [input("nombre: "),input("salario: ")]
    elif opcion == 2:
        try:
            empleados.pop(input("inserte cedula: "))    
        except KeyError:
            print("cedula no existe")

        lista = empleados.items()
    elif opcion == 3:
        llave = input("inserte valor a buscar: ")
        if llave in empleados:
            print(llave, "existe y contiene", empleados[llave], end="\n")
        else:
            print("no existe la cedula", llave)
    elif opcion == 4:
        print("CEDULA:   | NOMBRE    | SALARIO")
        for i in sorted (empleados.keys()) :  
            print(i, empleados[i], end = "\n") 
    elif opcion == 5:
        loop = 0
    else:
        print("opcion equivocada!")

