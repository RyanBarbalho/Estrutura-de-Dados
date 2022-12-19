ind = 0

class Node(object):
    def __init__(self, key):
        self.name = key
        self.count = ind
        self.left = None
        self.right = None
    
    def comparison(fatherlist, sonlist, size):
        resembles = 0
        for i in range (size):
            if fatherlist[i] == sonlist[i]:
                resembles+=1

        return resembles

    def insertRoot(self, value):
        self = Node(value)
        ind+=1

    def insert(self,LISTA , sonchar, value):

            if self is None:
                self = Node(value)
                self.count = ind
                ind+=1
            else:
                fatherchar = []

                index = self.count
                for i in range (4):
                    fatherchar.append(LISTA[index].charac[i])

                #chamar funcao semelhanca
                resemblance = Node.comparison(fatherchar, sonchar, 4)
            
                if resemblance <= 2: 

                    self.left.insert(self, LISTA, sonchar, value)
                elif resemblance > 2:
                    
                    self.right.insert(self, LISTA, sonchar, value)

    def printTree(self):
        if self is not None:
            self.left.printTree(self.left)
            print(self.name)
            self.right.printTree(self.right)

class lista(object):
    def __init__(self, name, car1,car2,car3,car4):
        self.name = name 
        self.charac = [car1,car2,car3,car4]
#criar lista         
LISTA = []
        


object1 = lista("bingus", "a","b","c","d")
LISTA.append(object1)

print("Digite o primeiro animal:")
name = input()
print("digite as 4 caracteristicas do animal: ", name)

caracteristic1 = input()
caracteristic2 = input()
caracteristic3 = input()
caracteristic4 = input()
object1 = lista(name,caracteristic1,caracteristic2,caracteristic3,caracteristic4)
LISTA.append(object1)
#criou a arvore com o animal raiz
 
tree = Node(name)
ind+=1

op = 4
index = 1
string = "\ndigite\n\t1 para adicionar um animal a arvore\n\t0 para sair\n:"

while op != 0:
    print(string)
    op = int(input())
    match op:
        case 0:
            break
        case 1:
            index+=1
            print("digite o seu animal:")
            animalName = input()
            print("digite as 4 caracteristicas do animal:")
            caracteristic1 = input()
            caracteristic2 = input()
            caracteristic3 = input()
            caracteristic4 = input()
            newObject = lista(animalName, caracteristic1,caracteristic2,caracteristic3,caracteristic4)
            LISTA.append(newObject)
            Node.insert(tree, LISTA, LISTA[index].charac, animalName)

            break
        case 2:
            Node.printTree(tree)
            break

