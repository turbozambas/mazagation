// ----------------------
// Funções principais
// ----------------------

function dobro(n) {
  return n * 2;
}

function maiorNumero(a, b) {
  return a > b ? a : b;
}

function calcularIMC(peso, altura) {
  const imc = peso / (altura * altura);
  return imc.toFixed(2);
}

function tabuada(n) {
  let resultado = "";
  for (let i = 1; i <= 10; i++) {
    resultado += `${n} x ${i} = ${n * i}<br>`;
  }
  return resultado;
}

// ----------------------
// Funções de teste (ligadas aos botões)
// ----------------------

function testeDobro() {
  const valor = prompt("Introduz um número:");
  const res = dobro(Number(valor));
  mostrar(`O dobro de ${valor} é ${res}.`);
}

function testeMaiorNumero() {
  const a = prompt("Primeiro número:");
  const b = prompt("Segundo número:");
  const res = maiorNumero(Number(a), Number(b));
  mostrar(`O maior número entre ${a} e ${b} é ${res}.`);
}

function testeIMC() {
  const peso = prompt("Peso (kg):");
  const altura = prompt("Altura (m):");
  const imc = calcularIMC(Number(peso), Number(altura));
  mostrar(`O teu IMC é ${imc}.`);
}

function testeTabuada() {
  const n = prompt("Número para a tabuada:");
  const res = tabuada(Number(n));
  mostrar(res);
}

// ----------------------
// Utilidade para mostrar resultados
// ----------------------

function mostrar(texto) {
  document.getElementById("resultado").innerHTML = texto;
}
