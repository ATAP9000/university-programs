import random
opcion = 0
contador = 0
cola = []
print("programa de cola hecho con listas en python \n en este programa se tendra una cola de 20 personas insertados a voluntad del usuario..")
loop = 1
while loop == 1:
    opcion = input("MENU: \n 1.alguien llega \n 2.a quien se atiende \n 3.resultado \n 4.personas atentidas \n 5.fin \n")
    opcion = int(opcion)
    if opcion == 1:
        if len(cola) < 20:
            cola.append(random.choice(['hombre', 'mujer', 'algo']))
            print("ha llegado alguien y parece ser", cola[-1])
        if len(cola) == 20:
            print("cola llena! \n")
    elif opcion == 2:
        if len(cola) > 0:
            print("esta siendo atendid@:", cola[0])
        if len(cola) == 0:
            print("la cola esta vacia! \n")
    elif opcion == 3:
        if len(cola) > 0:
            print("ha sido atendid@:", cola[0])
            cola.pop(0)
            if len(cola) == 0:
                print("la cola esta vacia! \n")
                continue
            if len(cola) > 0:
                print("y ahora le toca a", cola[0])
            contador += 1
        if len(cola) == 0:
            print("la cola esta vacia! \n")
    elif opcion == 4:
        print("se han atendido:", contador , "personas! \n")
    elif opcion == 5:
        loop = 0 
    else:
        print("opcion equivocada!")


        
