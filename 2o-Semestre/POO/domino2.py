import random

class Jogo:
    def __init__(self):
        self.__jogadores = []
        self.dominoSet = DominoSet()
        self.__rodada = 0
        self.__tabuleiro = ""
        self.__extremidades = {
            "left": -1,
            "right": -1
        }

    def iniciar(self) -> None:
        self.__jogadores = [Jogador("IA"), Jogador("Você")]
        Ia = self.__jogadores[0]
        Voce = self.__jogadores[1]

        Ia.dar_pedras()
        Voce.dar_pedras()
        print(f"Suas pedras:")
        print("  ".join(Voce.mostrar_pecas()))

        Ia_carrossel = Ia.carrossel()
        Voce_carrosel = Voce.carrossel()

        
        if len(Ia_carrossel) == 0 and len(Voce_carrosel) == 0:
            self.rodada = 1 #Eu começo sempre, to nem aí
            print("Entrou aqui")
            return

        sair = False
        for pedra in self.dominoSet.getCarrosseis():
            for flag in Ia_carrossel:
                if str(pedra) == str(flag):
                    self.__rodada = 1
                    print("Tabuleiro:")
                    self.__tabuleiro += str(pedra)
                    print(self.__tabuleiro)
                    self.__extremidades["left"], self.__extremidades["right"] = pedra.left(), pedra.right()
                    self.__jogadores[1].jogar_pedra(pedra)
                    sair = True
                    break
            
            if sair:
                break

            for flag in Ia_carrossel:
                if str(pedra) == str(flag):
                    self.rodada = 0
                    print("Tabuleiro:")
                    self.__tabuleiro += str(pedra)
                    print(self.__tabuleiro)
                    self.__extremidades["left"], self.__extremidades["right"] = pedra.left(), pedra.right()
                    self.__jogadores[1].jogar_pedra(pedra)
                    sair = True
                    break
            
            if sair:
                break
        
        print("--------------------")
        print("indo pra 2a rodada:")
        self.proximaRodada()

    def proximaRodada(self) -> None:
        print(f"Tabuleiro Atual: {self.__tabuleiro}")

        if self.__rodada % 2 == 0: #Rodada da Ia
            jogou = False
            #adicionar à esquerda
            for pedra in self.__jogadores[0].getPedras():
                if pedra.left() == self.__extremidades["left"]:
                    pedra.inverte()
                    self.__tabuleiro = str(pedra) + self.__tabuleiro
                    jogou = True
                
                if pedra.right() == self.__extremidades["left"]:
                    self.__tabuleiro = str(pedra) + self.__tabuleiro
                    jogou = True

            #adicionar à direita
            for pedra in self.__jogadores[0].getPedras():
                if pedra.left() == self.__extremidades["right"]:
                    self.__tabuleiro += str(pedra)
                    jogou = True
                
                if pedra.right() == self.__extremidades["right"]:
                    pedra.inverte()
                    self.__tabuleiro = str(pedra) + self.__tabuleiro
                    jogou = True
                
            if not jogou:
                nova_peca = self.dominoSet.pegar_peca()
                self.__jogadores[0].pegar_uma_peca(nova_peca)

        if self.__rodada % 2 == 1: #Rodada do Usuário
            jogou = False
            
            print("Suas pedras:")
            print("  ".join(self.__jogadores[1].mostrar_pecas()))
            pedra_selecionada = input("escolha a peça que quer jogar (numero|numero): ")
            left, right = int(pedra_selecionada[0]), int(pedra_selecionada[2])
            
            #verificar se ele tem essa pedra e selecionala
            pedra_jogada = None
            for pedra in self.__jogadores[1].getPedras():
                if pedra.left() == left and pedra.right() == right:
                    pedra_jogada = pedra
                    break
            
            if pedra_jogada == None:
                print("Pedra indisponivel, tente novamente")
                self.proximaRodada()
                return

            lado = input("onde quer jogar (E/D): ")
            self.__jogadores[1].jogar_pedra(pedra_jogada)

            if lado == "E":
                if pedra_jogada.left() == self.__extremidades["left"]:
                    print("Ok")
                if pedra_jogada.right() == self.__extremidades["left"]:
                    print("Ok")

            if lado == "D":
                if pedra_jogada.left() == self.__extremidades["right"]:
                    print("Ok")
                if pedra_jogada.right() == self.__extremidades["right"]:
                    print("Ok")


        self.__rodada += 1
        print("-------------------------")
        print(f"Rodada {self.__rodada}")
        self.proximaRodada()

class Jogador(Jogo):
    def __init__(self, nome: str):
        super().__init__()
        self.__nome = nome
        self.__pedras = []
    
    def dar_pedras(self):
        self.__pedras = random.choices(self.dominoSet.getSet(), k=7)
        for pedra in self.__pedras:
            if pedra in self.dominoSet.getSet():
                self.dominoSet.getSet().remove(pedra)

    def carrossel(self) -> list:
        carrosseis = []
        for pedra in self.dominoSet.getSet():
            if pedra.left() == pedra.right():
                carrosseis.append(pedra)
        
        return carrosseis
    
    def getPedras(self) -> list:
        return self.__pedras
    
    def getNome(self) -> str:
        return self.__nome
    
    def pegar_uma_peca(self, peca: "Domino"):
        self.__pedras.append(peca)
    
    def mostrar_pecas(self) -> list:
        return [str(pedra) for pedra in self.__pedras]

    def jogar_pedra(self, pedra: "Domino"):
        if pedra in self.__pedras:
            self.__pedras.remove(pedra)

class DominoSet(Jogo):
    def __init__(self):
        self.__set = [Domino(a, b) for a in range (7) for b in range (a, 7)]
        self.__carrosseis = [Domino(6-a, 6-a) for a in range (7)]
    
    def getSet(self) -> list:
        return self.__set
    
    def getCarrosseis(self) -> list:
        return self.__carrosseis
    
    def pegar_peca(self) -> "Domino":
        try:
            pedra = self.__set[random.randint(0, len(self.__set))]
            self.__set.remove(pedra)
            return pedra
        except:
            print("Acabaram as pedras. Acabou o jogo")
    
class Domino(DominoSet):
    def __init__(self, v1: int, v2: int):
        self.pedra = [v1, v2]

    def __str__(self):
        return f"[{self.pedra[0]} : {self.pedra[1]}]"
    
    def left(self) -> int:
        return self.pedra[0]
    
    def right(self) -> int:
        return self.pedra[1]

    def inverte(self):
        self.pedra[0], self.pedra[1] = self.pedra[1], self.pedra[0]
    
jogo = Jogo()
jogo.iniciar()