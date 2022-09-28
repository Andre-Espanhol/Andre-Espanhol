var ordinais = ['primeira', 'segunda', 'terceira', 'quarta'];
var media=0;

for (var i = 0; i < ordinais.length; i++) {
    var nota = prompt("Informe a " + ordinais[i] + " nota: ");
    if (nota === "" || !nota) nota = 0;
    media += parseFloat(nota,2);
}

media /= ordinais.length;

if (media >= 6) {
    document.write("Aprovado");
} else if (media <= 5) {
    document.write("Reprovado");
} else {
    document.write("Recuperação");
}