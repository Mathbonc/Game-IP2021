#include "raylib.h"
#include <string.h>
#include <stdlib.h>

int charcont[48]={0};
const char fala00[]="GAME OVER";
const char fala01[]="Em um lugar distante porém conhecido (Recife),\numa professora se vê rodeada por perigos inéditos\nem uma situação apocalíptica.\n        Precione Enter";
const char fala02[]="Professora Rubens: Vish, gente. O que aconteceu aqui?\nProcurei em todo canto e não achei as provas dos meus alunos,\ndemorei tanto pra jogar esses dados pra corrigi-las...\nAh, achei algumas aqui no meu baú sem fundo onde eu as guardo.";
const char fala03[]="Professora Rubens: O jeito agora é procurar pelos alunos\ne ver se acho alguma pista do que está acontecendo.";

//--------------------------------------------------------------------------------------Rubens encontra Leão Nidas-------------------------------------------------------------------------

const char fala04[]="Professora Rubens: Meu aluno, Leão Nidas,\no que está fazendo aqui? Como você está?";
const char fala05[]="Leão Nidas: Hoje acordei e pensei que estava em um pesadelo,\nmas agora, como encontrei com a senhora, tenho certeza. ;-;. ";

//--------------------------------------------------------------------------------------Rubens derrota Leão Nidas-------------------------------------------------------------------------

const char fala06[]="Professora Rubens: Meu Deus, Leão Nidas, que desânimo!\nTome aqui sua nota, coloquei zero, mas na próxima você recupera.";
const char fala07[]="Leão Nidas: Muito linda você, tenha um bom dia e nem se preocupe,\nnão vou ficar falando mal de você no grupo do WhatsApp nem nada do tipo…";

//--------------------------------------------------------------------------------------Leão Nidas sai-------------------------------------------------------------------------

const char fala08[]="Antes de entregar a prova a Leão Nidas,\nRubens enxerga algo escrito nela\n'A nota era certa, o resultado não se equiparou a oferta'.";
const char fala09[]="Professora Rubens: Que estranho,\nessa letra é muito feia, lembro dela em algum lugar…";

//--------------------------------------------------------------------------------------Rubens encontra Ro Brigo-------------------------------------------------------------------------

const char fala10[]="Ro Brigo: Finalmente encontrei você,\nnossa batalha será mais que lendária!";
const char fala11[]="Professora Rubens: Ai meu Deus, meu pior pesadelo…";
const char fala12[]="Ro Brigo: O que disse? Eu ouvi isso,\nvejo que a senhora ainda está nos caminhos rasos\ndos cálculos que vem antes do sexto, patético.";

//--------------------------------------------------------------------------------------Rubens derrota Ro Brigo-------------------------------------------------------------------------

const char fala13[]="Professora Rubens: Bem Ro Brigo, já deu né, tome aqui seu 1,5,\nespero que não fique chateado com sua nota,\nnão é uma nota ruim pra quem pagou essa matéria 5 vezes…";
const char fala14[]="Ro brigo: Obrigado professora, até semestre que vem.";

//--------------------------------------------------------------------------------------Ro Brigo sai-------------------------------------------------------------------------

const char fala15[]="Rubens nota, que perto da testa de Ro Brigo há algo escrito\ncom as mesmas letras que ela leu anteriormente\n'O segredo é mais obscuro, a equação tinha um furo'.";
const char fala16[]="Professora Rubens: Equação com furo, ela era contínua?\nEstava definida no ponto?";

//--------------------------------------------------------------------------------------Rubens encontra MuLittle-------------------------------------------------------------------------

const char fala17[]="MuLittle: Professora…";
const char fala18[]="Professora Rubens: Que voz de sono é essa MuPequeno?\nComeu seu café da manhã apocalíptico hoje não? Haha.";
const char fala19[]="MuLittle: Haha, professora, sempre muito engraçado suas piadas,\nmas não achei minha geladeira, infelizmente.";

//--------------------------------------------------------------------------------------Rubens derrota MuLittle-------------------------------------------------------------------------

const char fala20[]="Professora Rubens: Triste pela sua geladeira,\ntome aqui seu 3, adicionei uns décimos pela nossa situação atual,\nimportante né.";
const char fala21[]="MuLittle: Ok professora, até mais (mais nunca).";

//--------------------------------------------------------------------------------------MuLittle sai-------------------------------------------------------------------------

const char fala22[]="A Professora Rubens observou, ao olhar bem para baixo,\nque os cabelos de MuLittle formavam a frase\n'Ele era com ela, ela não o suportava, ele não a suportou'.";
const char fala23[]="Professora Rubens: Que cabelos sedosos…";

//--------------------------------------------------------------------------------------Rubens encontra com X Anny-------------------------------------------------------------------------

const char fala24[]="X Anny: Professora, como vai (pra longe de mim)?";
const char fala25[]="Professora Rubens: Ei, eu escutei você sussurrando aí viu?\nQue galinha linda, Anny e sua galinha, “A Galinha de Anny”.";
const char fala26[]="X Anny: O certo é “A Galinha de X”,\nleia meu nome minha senhora!";

//--------------------------------------------------------------------------------------Rubens derrota X Anny-------------------------------------------------------------------------

const char fala27[]="Professora Rubens: Tome sua nota X Anny,\ncuidado pra galinha não comer hein haha.";
const char fala28[]="X Anny: 2 pontos professora? Vou falar mais nada,\nvamos H’(x) não se junte com essa gentalha!";

//--------------------------------------------------------------------------------------X Anny sai-------------------------------------------------------------------------

const char fala29[]="Rubens percebe em uma das penas da galinha algo estranho:\n'O plano era simples, a execução..'.";
const char fala30[]="Professora Rubens: Meu Deus gente!\nEsses lugares que essas mensagens aparecem tão bem estranhos né,\nmas vamos lhá.";

//--------------------------------------------------------------------------------------Rubens encontra Freddy Rico-------------------------------------------------------------------------

const char fala31[]="Professora Rubens: Meu Deus Freddy Rico\ncomo você está diferente, cortou o cabelo? ";
const char fala32[]="Freddy Rico: Finalmente me encontrou, rã.";
const char fala33[]="Professora Rubens: Pois é, pera aí...";
const char fala34[]="Freddy Rico: Isso mesmo, fui eu que espalhei todas essas mensagens,\ninclusive fui eu o responsável por esse cenário apocalíptico.";
const char fala35[]="Professora Rubens: Por que e como você fez isso? :o";
const char fala36[]="Freddy Rico: Fiz isso tudo porque a senhora desconsiderou uma questão minha\nquando eu deixei de justificar a derivada da função que eu fiz,\na questão nem justificativa pedia... ";
const char fala37[]="Professora Rubens: Ai Freddy Rico, isso é só um detalhe,\ncada prova é cada prova e cada professor é cada professor.";
const char fala38[]="Freddy Rico: Professora, com todo o respeito, a senhora falou muito, Mas não falou nada -_- ";
const char fala39[]="Professora Rubens: Esqueça isso, você ainda tá no sétimo período,\nmas mudando de assunto, como que você fez tudo isso?";
const char fala40[]="Freddy Rico: Eu tô no oitavo período “tecnicamente”,\nsobre como eu fiz, bem, eu tenho meus contatos.";

//--------------------------------------------------------------------------------------Rubens ganha de Freddy Rico-------------------------------------------------------------------------

const char fala41[]="Freddy Rico: Cadê minha nota?";
const char fala42[]="Professora Rubens: Infelizmente não tenho ela corrigida,\nmas lhe entrego amanhã...";
const char fala43[]="Freddy Rico: NÃAAAAAAAAAAAAAAAAAAAAAAAAAAAAOOOOOOOOOOOOO";
const char fala44[]="E nunca mais as notas de Freddy Rico foram vistas.";

//--------------------------------------------------------------------------------------Rúbia perde-------------------------------------------------------------------------

const char fala45[]="Email: Professora Rubens, a universidade pede\nque você faça provas condizentes com o assunto visto\ne com os exercícios passados em sala.";
const char fala[]="NÃAAAAAAAAAAAAAAAAAAAAAAAAAAAAOOOOOOOOOOOOO";
const char fala[]="E nunca mais os dados de Rubens foram vistos.";

