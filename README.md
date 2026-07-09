# Projeto pessoal de implementação e treinamento de uma rede neural

O presente projeto implementa uma rede neural artificial, cuja camada oculta pode variar de tamanho, e a treina para resolver o problema da porta lógica XOR.

Em particular, chama-se atenção para o uso de um arquivo *Makefile* para otimizar o processo de compilação; a sua utilização garante que arquivos que não sofreram alterações não sejam recompilados desnecessariamente.

## Modo de uso:

```bash
make build 
```

```bash
cd bin

./run
```

## Resultados:

Se a resposta correta for zero, a linha 0 deve ter a maior probabilidade; se a resposta correta for um, a linha 1 deve ter a maior probabilidade.

```bash
It's running!
Resposta da rede: 
0.885247 
0.107484 
Resposta certa: 
0

Resposta da rede: 
0.113578 
0.893592 
Resposta certa: 
1

Resposta da rede: 
0.113578 
0.893592 
Resposta certa: 
1

Resposta da rede: 
0.113578 
0.893592 
Resposta certa: 
1

Resposta da rede: 
0.880684 
0.111953 
Resposta certa: 
0

Resposta da rede: 
0.885247 
0.107484 
Resposta certa: 
0

Resposta da rede: 
0.885247 
0.107484 
Resposta certa: 
0

Resposta da rede: 
0.880684 
0.111953 
Resposta certa: 
0

Resposta da rede: 
0.146216 
0.861726 
Resposta certa: 
1

Resposta da rede: 
0.146216 
0.861726 
Resposta certa: 
1
```
