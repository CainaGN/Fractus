# Fractus

Fractus é um gerador de árvores fractais desenvolvido em C utilizando a biblioteca [raylib](https://www.raylib.com/). 

O projeto surgiu como um experimento para entender o funcionamento de **Fractal Canopy**. Inicialmente, as ramificações eram perfeitamente simétricas e uniformes, mas evoluíram com a adição de elementos de aleatoriedade para proporcionar uma aparência mais natural e orgânica às árvores geradas.

## ✨ Características

- Geração de árvores fractais em tempo real.
- Variações aleatórias no comprimento e ângulo das ramificações.
- Transição de cores (marrom para os galhos e verde para as folhas/extremidades).
- Espessura dinâmica baseada na profundidade da recursão.

## 🚀 Como Compilar e Executar

### Pré-requisitos

Certifique-se de ter o `gcc` e a biblioteca `raylib` instalados em seu sistema Linux.

### Compilação

Para compilar o código, utilize o seguinte comando no terminal:

```bash
gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o Fractus
```

### Execução

Após a compilação, execute o programa:

```bash
./Fractus
```

## 🛠️ Tecnologias Utilizadas

- **Linguagem C**
- **Raylib**: Para renderização gráfica e gerenciamento de janela.
- **Matemática**: Uso de funções trigonométricas para o cálculo das ramificações.

---

*Desenvolvido como um estudo sobre fractais e recursividade.*
