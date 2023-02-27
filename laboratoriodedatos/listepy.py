empleados = {}


empleados[input("cedula: ")] = [input("nombre: "),input("salario: ")]
empleados[input("cedula: ")] = [input("nombre: "),input("salario: ")]
empleados[input("cedula: ")] = [input("nombre: "),input("salario: ")]
lista = empleados.items()
for x in lista:
    print (x)
    print ("\n")
del empleados[input("cedula: ")]
for x in lista:
    print (x)
    print ("\n")

print(empleados[input("cedula: ")])
