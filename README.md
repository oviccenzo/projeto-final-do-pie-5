# Trabalho final PIE-V - Jogo Educativo e Ludico

## Proposta 

### [Documentação do projeto](https://drive.google.com/drive/u/2/folders/1Z9U8pYedcPm0KpiBdGozwl_4WV-sY12k)

O projeto final compreende utilizar uma versão 'moderna' do COBOL para criar um jogo educativo, fins lúdico.


Versões da linguagem COBOL para fins educativos e lúdicos
Versão / Ferramenta	Características	Vantagens para jogos educativos
Visual COBOL (Rocket Software)	Funciona em Visual Studio, Eclipse e VS Code. Suporte a depuração avançada, integração com C#, Java e linguagens modernas.	Permite criar jogos com interface gráfica, misturando COBOL com .NET ou Java. Ideal para projetos acadêmicos e protótipos lúdicos.
isCOBOL Evolve (Veryant)	Compilador COBOL 100% em Java, roda em qualquer plataforma com JVM. Suporte a JDBC/ODBC, depuração gráfica e execução em navegadores.	Excelente para jogos educativos web-based, pois o COBOL pode ser executado diretamente em browsers sem grandes alterações.
Hercules TK4/TK5 (Mainframe emulado)	Emuladores que rodam MVS 3.8j com compiladores COBOL clássicos.	Bom para fins históricos e didáticos, simulando ambiente mainframe. Menos indicado para jogos modernos, mas útil para ensinar fundamentos.
🎮 Considerações práticas para jogos educativos em COBOL

    Visual COBOL é a melhor escolha se você quer interfaces gráficas modernas e integração com ferramentas de programação atuais.

    isCOBOL Evolve é ideal para jogos web educativos, pois permite rodar COBOL em navegadores, integrando com HTML/JavaScript.

    Hercules TK4/TK5 são ótimos para ensino de história da computação, mas limitados para jogos lúdicos interativos.

⚠️ Restrições, limitações e desafios

    COBOL não foi projetado para jogos, mas sim para aplicações de negócios.

    Criar jogos lúdicos exige integração com outras linguagens (Java, C#, Python) para gráficos e interatividade.

    O uso de emuladores antigos (Hercules TK4/TK5) é mais voltado para ensino de mainframe, não para jogos modernos.

✅ Orientação 

1) Como o projeto final tem por finalidade ensinar COBOL de forma divertida, recomenda-se usar Visual COBOL em conjunto com Visual Studio ou Eclipse, criando jogos simples (quiz, desafios matemáticos, simuladores de negócios). Se a ideia é rodar jogos educativos em navegador, escolha isCOBOL Evolve, que permite portar COBOL para ambientes web sem perder compatibilidade.

2) A solução apresentada por cada uma das 2 ou 3 equipes, será realizada em uma escola da cidade (provavelmente Tonico Franco), na semana seguinte do dia 08/06 ou data a ser agendada.

3) A submissão compreende fazer o upload em uma pasta do Google Drive, compartilhar com o tipo de acesso (IFTM) e incluir o link compartilhado.

4) 

## Dependencias

- sdl2_dev
- sdl2_ttf

## Como rodar o projeto

### Clonar o repositorio (caso não o tenha localmente ainda)
`$ git clone git@github.com:oviccenzo/projeto-final-do-pie-5.git`

### Compilar o projeto usando makefile
`$ make`
ou
`$ make all`

### Rodar o executavel
`$ make run`

### Deletar e limpar o execultavel (isso apaga o executavel do seu computador)
`$ make clear`

## Detalhes

### O que é .PHONY no make file

Ele indica que 'all', 'run' e 'clear' são nomes de ação(passos) e não arquivos do computador ou variaveis

