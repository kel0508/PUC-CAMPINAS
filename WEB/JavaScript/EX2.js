// recebe um CPF e verifica se ele é válido
function validarCPF(cpf) {

    // retira os pontos e o traço do CPF deixando só numeros
    cpf = cpf.replaceAll(".", "").replace("-", "");


    // verifica se o CPF possui exatamente 11 números
    if (cpf.length != 11) {

        // se não tiver 11 números, o CPF é inválido
        return false;
    }

    // guarda a soma das multiplicações
    let soma = 0;

    // o primeiro número deve ser multiplicado por 10,
    // o segundo por 9, o terceiro por 8 e assim por diante
    let peso = 10;

    // percorre os 9 primeiros números do CPF
    for (let i = 0; i < 9; i++) {

        // pega cada número do CPF e transforma em número
        let numero = Number(cpf[i]);

        // multiplica o número pelo peso e adiciona na soma
        soma = soma + (numero * peso);

        // diminui o peso em 1 para a próxima multiplicação
        peso--;
    }


    // calcula o primeiro dígito usando o módulo 11
    let resultado = 11 - (soma % 11);


    // se o resultado for 10 ou 11, o dígito é 0
    if (resultado == 10 || resultado == 11) {
        resultado = 0;
    }


    // guarda o primeiro dígito calculado
    let primeiroDigito = resultado;

    // zera a soma para fazer um novo cálculo
    soma = 0;

    // o segundo dígito, o peso começa em 11
    peso = 11;


    // utilizamos o 9 primeiros numeros do CPF + o primeiro dígito calculado
    for (let i = 0; i < 10; i++) {

        // pega o número correspondente do CPF e transforma em número
        let numero = Number(cpf[i]);

        // quando chega no décimo número, usamos o primeiro dígito calculado
        if (i == 9) {
            numero = primeiroDigito;
        }

        // multiplica o número pelo peso e soma o resultado
        soma = soma + (numero * peso);

        // diminui o peso em 1
        peso--;
    }


    // calcula o segundo dígito usando o módulo 11
    resultado = 11 - (soma % 11);


    // se o resultado for 10 ou 11, o dígito é 0
    if (resultado == 10 || resultado == 11) {
        resultado = 0;
    }


    // guarda o segundo dígito calculado
    let segundoDigito = resultado;

    // pega o primeiro dígito que realmente ta no CPF
    let primeiroDigitoCPF = Number(cpf[9]);

    // pega o segundo dígito que realmente ta no CPF
    let segundoDigitoCPF = Number(cpf[10]);


    // compara os dígitos calculados com os dígitos que estão no CPF
    if (primeiroDigito == primeiroDigitoCPF &&
        segundoDigito == segundoDigitoCPF) {

        // se os dois forem iguais, o CPF é válido
        return true;

    } else {

        // se algum dos dois for diferente, o CPF é inválido
        return false;
    }
}

// pede para o usuário digitar um CPF
let cpf = prompt("Digite um CPF:");

// chama a função validarCPF passando o CPF digitado
if (validarCPF(cpf)) {

    // se a função retornar true, mostra que o CPF é válido
    alert("CPF válido!");

} else {

    // se a função retornar false, mostra que o CPF é inválido
    alert("CPF inválido!");
}
