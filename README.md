<h1 align = "center"> 🔒 Criptografia 🔓</h1>

<p align = "center"> Algoritmo para simulação de criptografia de mensagens ou senhas utilizando números primos. </p>

<p align="center">
 <a href="https://github.com/Vitor-Manoel-Silva-dos-Santos/criptografiaComNumerosPrimos/new/master?readme=1#-objetivo-">Objetivo</a> •
 <a href="https://github.com/Vitor-Manoel-Silva-dos-Santos/criptografiaComNumerosPrimos/new/master?readme=1#-etapas-do-projeto-">Etapas do projeto</a> • 
 <a href="https://github.com/Vitor-Manoel-Silva-dos-Santos/criptografiaComNumerosPrimos/new/master?readme=1#-tecnologias-">Tecnologias</a> • 
 <a href="https://github.com/Vitor-Manoel-Silva-dos-Santos/criptografiaComNumerosPrimos/new/master?readme=1#-fontes-">Fonte</a> • 
 <a href="https://github.com/Vitor-Manoel-Silva-dos-Santos/criptografiaComNumerosPrimos/new/master?readme=1#-autor-">Autor</a> 

<h5 href = "#objetivo"> Objetivo: </h5>

<p>Receber uma informação do usuário por teclado, criptografar a informação utilizando método de criptografia com números primos.</p>

<h5 href = "#etapas"> Etapas do projeto: </h5>

<table border="1">
    <tr>
        <th>Etapas: </th>
        <th>Descrição: </th>
    </tr>
    <tr>
        <td align="center">Entrada de informações</td>
        <td>Como foco inicial teve-se que construir um método de entrada de dados pela captura 
            da tecla digitada do teclado, para isso foi utilizado a biblioteca <i>conio.h</i>, assim armazenando a 
        informação digitada em um vetor, criando assim um algoritmo de armazenamento em tempo real com a função __malloc__ e __realloc__.</td>
    </tr>
    <tr> 
        <td align="center">Gerador de números primos</td>
        <td>Gerado números com a lib <i>stdlib.h</i>, foi criado um método com chamada recursiva
        para verificar se é um numero primo, caso não seja, gera-se outro número, até que a condição
    seja verdadeira.</td>
    </tr>
    <tr>
        <td align="center"> Armazenamento chaves <br>
        (para servidor) </td>
        <td>Pós geração de números primos (chaves) designasse três <b>chaves</b> ao servidor.
        <p>Exemplo: </p>
        <table align="center" border="1">
            <tr>
                <th><b>Chave 1</b></th>
                <th><b>Chave 2</b></th>
                <th><b>Chave 3</b></th>
            </tr>
            <tr>
                <td align="center">31</td>
                <td align="center">11</td>
                <td align="center">5</td>
            </tr>
            <tr>
                <td align="center"><b>Índice 0</b></td>
                <td align="center"><b>Índice 1</b></td>
                <td align="center"><b>Índice 2</b></td>
            </tr>
        </table>
        </td>
    </tr>
    <tr>
        <td align="center">Chave <i>pública usuário</i></td>
        <td>Criamos então a chave pública para criptografia da mensagem do usuário, multiplicando
            a chave do <b>índice 0</b> pela chave do <b>índice 1</b>.
            <table align="center" border="1">
                <tr>
                    <td align="center">
                        31 x 11 = 341
                    </td>
                </tr>
            </table>
        </td>
    </tr>
    <tr>
        <td align="center">Criptografia</td>
        <td>Gerada a chave para criptografar a mensagem, criptografasse pelo método de multiplicação 
            de cada caracter digitado (número da tabela ASCII) pela chave pública do usuário.
            <p>Demonstração: </p>
            <table border="1" align="center">
                <tr>
                    <th>Caracteres</th>
                    <td align="center">s</td>
                    <td align="center">e</td>
                    <td align="center">n</td>
                    <td align="center">h</td>
                    <td align="center">a</td>
                </tr>
                <tr>
                    <th>Valor ASCII</th>
                    <td align="center">115</td>
                    <td align="center">101</td>
                    <td align="center">110</td>
                    <td align="center">104</td>
                    <td align="center">97</td>
                </tr>
                <tr>
                    <th>Criptografado</th>
                    <td align="center">39215</td>
                    <td align="center">34441</td>
                    <td align="center">37510</td>
                    <td align="center">35464</td>
                    <td align="center">33077</td>
                </tr>
                <tr>
                    <td align="center" colspan="6" >Criptografado: 3921534441375103546433077</td>
                </tr>
            </table>
        </td> 
    </tr>       
    <tr>
        <td align="center">Armazenamento chaves<br>(para usuário)</td>
        <td>As chaves do usuário são: a chave pública para criptografar e a chave privada para envio.
        <p>Exemplo:</p>
            <table align="center" border="1">
                <tr>
                    <th><b>Chave pública</b></th>
                    <th><b>Chave privada</b></th>
                </tr>
                <tr>
                    <td align="center">341</td>
                    <td align="center">5</td>
                </tr>
                <tr>
                    <td align = "center"><b>Índice 0</b></td>
                    <td align = "center"><b>Índice 1</b></td>
                </tr>
            </table>
            <p>Se a chave de criptografia do usuário for verdadeira, a mensagem é criptografada, se 
                a chave de envio do usuário for verdadeira a mensagem é enviada.
            </p>
        </td>
    </tr>
    <tr>
        <td align="center"><i>Modificar chaves</i></td>
        <td>Para que sempre a criptografia seja diferente e as chaves sempre mudem, foi construído um
            método que muda as posições das chaves e gera uma nova.
        <p>Exemplo:</p>
            <table align="center" border="1">
                <tr>
                    <th><b>Chave 1</b></th>
                    <th><b>Chave 2</b></th>
                    <th><b>Chave 3</b></th>
                </tr>
                <tr>
                    <td align="center">11</td>
                    <td align="center">5</td>
                    <td align="center">"Nova chave"</td>
                </tr>
                <tr>
                    <td align="center"><b>Índice 0</b></td>
                    <td align="center"><b>Índice 1</b></td>
                    <td align="center"><b>Índice 2</b></td>
                </tr>
            </table>
            <table border="1" align="center">
                <tr>
                    <td><b>Chave pública</b></td>
                    <td><b>Chave privada</b></td>
                </tr>
                <tr>
                    <td align="center">55</td>
                    <td align="center">"Nova chave"</td>
                </tr>
                <tr>
                    <td align="center"><b>Índice 0</b></td>
                    <td align="center"><b>Índice 1</b></td>
                </tr>
            </table></td>
    </tr>
</table>
<h5 href = "#tecnologias"> Tecnologias: </h5>
<p>Algoritmo desenvolvido com linguagem C.</p>
<img src="https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white"/>

<h5 href = "#fonte"> Fontes: </h5>
<p><a href = "https://www.youtube.com/watch?v=dChr0TyQ6yc&t=825s" target="_blank"> 🔗</a> ¿Cómo funciona el cifrado de información?</p>
<p><a href = "https://www.youtube.com/watch?v=Q8K311s7EiM&t=283s" target="_blank"> 🔗</a> Cómo funciona la criptografía </p>

<h5 href = "#autor"> Autor: </h5>
<table border="0">
    <tr>
        <td align="center">
            <a href="https://github.com/Vitor-Manoel-Silva-dos-Santos" target="_blank"><img src="https://avatars.githubusercontent.com/u/83611513?v=4" height= "100" width= "100" /></a>
        </td>
    </tr>
    <tr>
        <td>
            <a href = "https://www.linkedin.com/in/vitor-manoel-s-santos/" target="_blank"> <img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/> </a>
        </td>
    </tr>
</table>
