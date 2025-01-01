# Listu

```Listu``` é um programa de gerenciamento de tarefas escrito em C para uso em linha de comando. Esse é um programa desenvolvido por mim para resolver um problema pessoal meu, que acabou tomando uma forma maior em termos de projeto.
Inicialmente eu só queria resolver o problema que eu tenho em não conseguir administrar bem as minhas tarefas dos meus projetos pessoais com aplicativos populares como Notion e Evernote, que embora sejam muito bons e muito bem consolidados eu sinceramente tinha uma dificuldade imensa não somente em usá-los mas em manter o "flow" depois de abrir um desses apps em outra janela.

## Para quem foi desenhado e para quê foi desenhado?

O foco do ```Listu``` é ser um programa simples de linha de comando e para uso direto em projetos de desenvolvimento de software, portanto é um programa muito mais focado para devs do que usuários comuns.

## Uso

Instale o ``Listu`` baixando o arquivo compactado release da última versão, com o pacote aberto vá para o diretório e digite ``make install``. Com o
programa corretamente instalado, digitando listu em seu terminal você verá algo semelhante a isso:

```bash
    Listu, v0.0.1

    Uso: listu [OPÇÃO]
    init                    Inicia diretório .listu 
    new  [ARQUIVO]          Cria lista de tarefas 
    add  [ARQUIVO] [TAREFA] Adiciona tarefas para arquivo 
    show [ARQUIVO]          Exibe tarefas de um arquivo 
    help                    Mostra este menu de ajuda 
```

Inicie o ```Listu``` diretamente na pasta do seu projeto da sua escolha:

```bash
    listu init
```

Crie uma nova lista de tarefas:

```bash
    listu new tarefas
```

Agora adicione novas tarefas a ele:

```bash
    listu add tarefas "Criar nova classe para objetos"
```

Com o seu listu criado e tarefa adicionada basta exibir no seu terminal e voi lá:

```bash
    listu show tarefas
```

Saída:

```bash
    Listu tarefas:
    * Criar nova classe para objetos
```
