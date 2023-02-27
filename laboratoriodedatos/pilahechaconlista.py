import random
opcion = 0
pila = []
print("programa de pilas empleando listas en python \n en este programa se tendra una pila de 20 platos insertados aleatoriamente a voluntad del usuario, estos seran rojo azul o amarillo.")
loop = 1
while loop == 1:
    opcion = input("MENU: \n 1.apilar \n 2.desapilar \n 3.tope \n 4.total en pila \n 5.fin \n")
    opcion = int(opcion)
    if opcion == 1:
        if len(pila) < 20:
            pila.append(random.choice(['azul', 'rojo', 'amarillo']))
            print("se ha metido un plato y es de color", pila[-1])
        if len(pila) == 20:
            print("pila llena! \n")
    elif opcion == 2:
        if len(pila) > 0:
            print("se ha removido un plato y es", pila[-1])
            pila.pop(-1)
        if len(pila) == 0:
            print("pila vacia! \n")
    elif opcion == 3:
        print("en el tope de la pila hay un plato", pila[-1])
    elif opcion == 4:
        opcion2 = input("de que color el plato? \n 1.azul \n 2.rojo \n 3.amarillo \n")
        opcion2 = int(opcion2)
        if opcion2 == 1:
            print("hay", pila.count('azul'), "platos azules \n")
        elif opcion2 == 2:
            print("hay", pila.count('rojo'), "platos rojos \n")
        elif opcion2 == 3:
            print("hay", pila.count('amarillos'), "platos amarillos \n")
        else:
            print("opcion no existe! \n")
    elif opcion == 5:
        loop = 0
    elif opcion ==6:
        print(pila)
    else:
        print("opcion equivocada!")

