import json
import sys
import os

pessoas = []
number = 0

class Carro:
    pass
    

class Pessoa:
    pass
    

def cadastroPessoa():
    global number
    p = Pessoa()
    pe = {}
    print("Digite o nome do proprietário:  \n")
    pe["nome"] = input()
    print("Digite seu cpf: \n")
    pe["cpf"] = input()
    for p in pessoas:
        if p["cpf"] == pe["cpf"]:
            print("CPF já cadastrado")
            input()
            menu()
    pe["chave"] = number
    number = number + 1
    pe["carros"] = []
    pessoas.append(pe)
    print("Cadastro feito com sucesso!")
    input()
    menu()

def cadastroCarro():
    validate = False
    c = Carro()
    ce = {}
    print("Informe o modelo do carro:\n")
    ce["modelo"] = input()
    c.modelo = ce["modelo"]
    print("Informe a placa do carro:\n")
    ce["placa"] = input()
    c.placa = ce["placa"]
    print("informe o cpf do proprietário do carro:\n")
    ce["cpfP"] = input()
    c.cpfP = ce["cpfP"]
    for p in pessoas:
        if p["cpf"] == ce["cpfP"]:
            p["carros"].append(ce)
            validate = True
    if(validate):
        print("Cadastro feito com sucesso!")
    else:
        print("CPF não encontrado")
    input()
    menu()

def visualizarCarro():
    print("Informe o cpf do proprietário dos carros:\n")
    cpf = input()
    for p in pessoas:
        if cpf == p["cpf"]:
            for c in p["carros"]:
                print("Modelo: "+c["modelo"]+"\n")
                print("Placa: "+c["placa"]+"\n")
    input()
    menu()

def menu():
    clear = lambda: os.system('clear')
    clear()
    print("*** Menu ***\n")
    print("1) Cadastrar Proprietário.\n")
    print("2) Cadastrar Carro.\n")
    print("3) Exibir Carros.\n")
    print("4) Apagar.\n")
    print("5) Sair.\n")
    choice = input()
    if choice == "1":
        cadastroPessoa()
    if choice == "2":
        cadastroCarro()
    if choice == "3":
        visualizarCarro()
    if choice == "4":
        apagar()
    if choice == "5":
        savetofile()

def savetofile():
    pessoaObj = {}
    pessoaObj["Pessoas"] = []
    for p in pessoas:
        carroObj = []
        for c in p["carros"]:
            carroObj.append({
                'modelo': c["modelo"],
                'placa': c["placa"],
                'cpfP': c["cpfP"]
            })
        pessoaObj["Pessoas"].append({
            'nome': p["nome"],
            'cpf': p["cpf"],
            'chave': p["chave"],
            'carros': carroObj
        })
    with open('data.txt', 'w') as outfile:
      json.dump(pessoaObj, outfile)
    sys.exit()
def main():
    global pessoas
    try:
        with open('data.txt') as pessoafile:
            datapessoa = json.load(pessoafile)
            for pd in datapessoa["Pessoas"]:
                p = Pessoa()
                pe = {}
                pe["nome"] = pd["nome"]
                pe["cpf"] = pd["cpf"]
                pe["carros"] = pd["carros"]
                pe["chave"] = pd["chave"]
                pessoas.append(pe)
    except:
        pass
    menu()

if __name__ == '__main__':
    main()



