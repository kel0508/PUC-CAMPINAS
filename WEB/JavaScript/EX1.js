//soma todos os divisores de um número
function somarDivisores(numero) {

    //guarda o resultado da soma
    let soma = 0;

    // o contador começa em 1 e vai até antes do próprio número
    // faz com que o número não seja considerado como divisor
    for (let i = 1; i < numero; i++) {

        // verifica se o número é divisível pelo contador
        if (numero % i == 0) {

            // adiciona o divisor encontrado na variável soma
            soma = soma + i;
        }
    }

    // retorna o resultado da soma dos divisores
    return soma;
}


// verfiica se os dois números são amigos
function verificarAmigos(numero1, numero2) {

    // soma os divisores do primeiro número
    let soma1 = somarDivisores(numero1);

    // soma os divisores do segundo número
    let soma2 = somarDivisores(numero2);

    // verifica se a soma dos divisores do primeiro número é igual ao segundo número E se a soma dos divisores do segundo é igual ao primeiro
    if (soma1 == numero2 && soma2 == numero1) {

        // se as duas condições forem verdadeiras, retorna verdadeiro
        return true;

    } else {

        // se alguma das condições for falsa, retorna falso
        return false;
    }
}

// pede para o usuário digitar o primeiro número
// number transforma o valor digitado em número
let numero1 = Number(prompt("Digite o primeiro número natural:"));


// pede para o usuário digitar o segundo número
let numero2 = Number(prompt("Digite o segundo número natural:"));


// chama a função para verificar se os números são amigos
if (verificarAmigos(numero1, numero2)) {

    // se a função retornar true, mostra que são amigos
    alert("Os números são amigos!");

} else {

    // se a função retornar false, mostra que não são amigos
    alert("Os números não são amigos!");
}

