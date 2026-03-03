# Fractus

Fractus é um gerador de árvores fractais desenvolvido em C utilizando a biblioteca [raylib](https://www.raylib.com/). 

O projeto surgiu como um experimento para entender o funcionamento de **Fractal Canopy**. Inicialmente, as ramificações eram perfeitamente simétricas e uniformes, mas evoluíram com a adição de elementos de aleatoriedade para proporcionar uma aparência mais natural e orgânica às árvores geradas.


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

