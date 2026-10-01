// soma todos os divisores de um número
function somarDivisores(numero) {

    // guarda a soma dos divisores
    let soma = 0;

    // começa em 1 e vai até antes do próprio número
    for (let i = 1; i < numero; i++) {

        // verifica se o número é divisível por i
        if (numero % i == 0) {

            // se for divisor, adiciona na soma
            soma = soma + i;
        }
    }

    // retorna a soma dos divisores
    return soma;
}


// verifica se dois números são amigos
function verificarAmigos(numero1, numero2) {

    // soma os divisores do primeiro número
    let soma1 = somarDivisores(numero1);

    // soma os divisores do segundo número
    let soma2 = somarDivisores(numero2);

    // verifica se a soma dos divisores do primeiro é igual ao segundo e se a soma dos divisores do segundo é igual ao primeiro
    if (soma1 == numero2 && soma2 == numero1) {

        // se as duas condições forem verdadeiras, os números são amigos
        return true;

    } else {

        return false;
    }
}

let min = Number(prompt("Digite o valor mínimo:"));

let max = Number(prompt("Digite o valor máximo:"));

// guardaos pares de números amigos encontrados
let resultado = "";


// anda todos os números começando pelo mínimo até chegar ao máximo
for (let numero1 = min; numero1 <= max; numero1++) {

    // começa o segundo número depois do primeiro para não verificar o mesmo par de novo
    for (let numero2 = numero1 + 1; numero2 <= max; numero2++) {

        // verifica se os dois números são amigos
        if (verificarAmigos(numero1, numero2)) {

            // se forem amigos, adiciona o par no resultado
            resultado = resultado + numero1 + " e " + numero2 + "\n";
        }
    }
}

// verifica se algum par de números amigos foi encontrado
if (resultado != "") {

    // mostra todos os pares encontrados
    alert("Pares de números amigos encontrados:\n\n" + resultado);

} else {

    // caso nenhum par tenha sido encontrado
    alert("Não foram encontrados números amigos");
}

