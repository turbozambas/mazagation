// ===============================
// Ficheiro: funcoes_treino2.js
// ===============================

// ---------- (A) AS FUNÇÕES (como no teu enunciado) ----------

// 1️⃣ Dobro do número
function dobro(n) {
  return n * 2;
}

// 2️⃣ Maior número
function maiorNumero(a, b) {
  return a > b ? a : b;
}

// 3️⃣ Converter horas em minutos
function horasParaMinutos(horas) {
  return horas * 60;
}

// 4️⃣ Verificar idade
function verificarIdade(idade) {
  return idade >= 18 ? "Maior de idade" : "Menor de idade";
}

// 5️⃣ Calcular IMC
function calcularIMC(peso, altura) {
  const imc = peso / (altura * altura);
  return Number(imc.toFixed(2));
}

// 6️⃣ Converter minutos em horas e minutos
function converterTempo(minutosTotais) {
  const horas = Math.floor(minutosTotais / 60);
  const minutos = minutosTotais % 60;
  const h = horas === 1 ? "hora" : "horas";
  const m = minutos === 1 ? "minuto" : "minutos";
  return `${horas} ${h} e ${minutos} ${m}`;
}

// 7️⃣ Positivo, negativo ou zero
function verificarNumero(n) {
  if (n > 0) return "Positivo";
  if (n < 0) return "Negativo";
  return "Zero";
}

// 8️⃣ Tabuada
function tabuada(n) {
  const linhas = [];
  for (let i = 1; i <= 10; i++) {
    linhas.push(`${n} x ${i} = ${n * i}`);
  }
  return linhas.join("\n");
}

// 9️⃣ Palavra curta ou longa
function verificarPalavra(palavra) {
  return palavra.length < 5 ? "Curta" : "Longa";
}

// 🔟 Soma de um array
function somarArray(numeros) {
  return numeros.reduce((acc, n) => acc + n, 0);
}

// ---------- (B) UTILITÁRIOS DE UI ----------

// lê um número (float) de um input; se vazio, devolve NaN
function getNum(id) {
  const v = document.getElementById(id).value.trim();
  return v === "" ? NaN : Number(v);
}

// lê um texto
function getTxt(id) {
  return document.getElementById(id).value;
}

// mostra texto/resultado numa <div class="out">
function setOut(id, texto) {
  document.getElementById(id).textContent = String(texto);
}

// parse de "10, 20, 30" -> [10,20,30] (ignora espaços e entradas vazias)
function parseArrayNum(id) {
  const raw = document.getElementById(id).value;
  const arr = raw.split(",").map(s => s.trim()).filter(s => s !== "");
  const nums = arr.map(Number);
  const temNaN = nums.some(n => Number.isNaN(n));
  return { nums, temNaN };
}

// pequena ajuda para validações simples
function assertNumero(n, campo = "valor") {
  if (Number.isNaN(n)) {
    throw new Error(`Por favor, introduz um número válido em "${campo}".`);
  }
}

// ---------- (C) LIGAR BOTÕES ÀS FUNÇÕES ----------

document.addEventListener("DOMContentLoaded", () => {
  // 1) Dobro
  document.getElementById("btn-dobro").addEventListener("click", () => {
    try {
      const n = getNum("n-dobro");
      assertNumero(n, "Número");
      setOut("out-dobro", `dobro(${n}) = ${dobro(n)}`);
    } catch (e) { setOut("out-dobro", e.message); }
  });

  // 2) Maior número
  document.getElementById("btn-maior").addEventListener("click", () => {
    try {
      const a = getNum("n-maior-a");
      const b = getNum("n-maior-b");
      assertNumero(a, "a");
      assertNumero(b, "b");
      setOut("out-maior", `maiorNumero(${a}, ${b}) = ${maiorNumero(a, b)}`);
    } catch (e) { setOut("out-maior", e.message); }
  });

  // 3) Horas para minutos
  document.getElementById("btn-horas").addEventListener("click", () => {
    try {
      const h = getNum("n-horas");
      assertNumero(h, "Horas");
      setOut("out-horas", `horasParaMinutos(${h}) = ${horasParaMinutos(h)}`);
    } catch (e) { setOut("out-horas", e.message); }
  });

  // 4) Verificar idade
  document.getElementById("btn-idade").addEventListener("click", () => {
    try {
      const idade = getNum("n-idade");
      assertNumero(idade, "Idade");
      setOut("out-idade", `verificarIdade(${idade}) = ${verificarIdade(idade)}`);
    } catch (e) { setOut("out-idade", e.message); }
  });

  // 5) IMC
  document.getElementById("btn-imc").addEventListener("click", () => {
    try {
      const peso = getNum("n-peso");
      const altura = getNum("n-altura");
      assertNumero(peso, "Peso");
      assertNumero(altura, "Altura");
      if (altura <= 0) throw new Error("A altura deve ser maior que zero.");
      setOut("out-imc", `calcularIMC(${peso}, ${altura}) = ${calcularIMC(peso, altura)}`);
    } catch (e) { setOut("out-imc", e.message); }
  });

  // 6) Converter tempo
  document.getElementById("btn-tempo").addEventListener("click", () => {
    try {
      const min = getNum("n-minutos");
      assertNumero(min, "Minutos totais");
      setOut("out-tempo", `converterTempo(${min}) = ${converterTempo(min)}`);
    } catch (e) { setOut("out-tempo", e.message); }
  });

  // 7) Verificar número
  document.getElementById("btn-numero").addEventListener("click", () => {
    try {
      const n = getNum("n-verificar");
      assertNumero(n, "Número");
      setOut("out-numero", `verificarNumero(${n}) = ${verificarNumero(n)}`);
    } catch (e) { setOut("out-numero", e.message); }
  });

  // 8) Tabuada
  document.getElementById("btn-tabuada").addEventListener("click", () => {
    try {
      const n = getNum("n-tabuada");
      assertNumero(n, "Número da tabuada");
      setOut("out-tabuada", `Tabuada do ${n}\n` + tabuada(n));
    } catch (e) { setOut("out-tabuada", e.message); }
  });

  // 9) Verificar palavra
  document.getElementById("btn-palavra").addEventListener("click", () => {
    const p = getTxt("txt-palavra");
    setOut("out-palavra", `verificarPalavra("${p}") = ${verificarPalavra(p)}`);
  });

  // 10) Somar array
  document.getElementById("btn-array").addEventListener("click", () => {
    try {
      const { nums, temNaN } = parseArrayNum("txt-array");
      if (nums.length === 0) throw new Error("Introduz pelo menos um número.");
      if (temNaN) throw new Error("Usa apenas números separados por vírgulas (ex.: 2, 4, 6).");
      setOut("out-array", `somarArray([${nums.join(", ")}]) = ${somarArray(nums)}`);
    } catch (e) { setOut("out-array", e.message); }
  });
});
