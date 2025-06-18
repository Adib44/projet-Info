function verifier(input, estCorrect) {
    let score;
  const conteneurQuestion = input.closest('.question');
  const champReponse = conteneurQuestion.querySelector('.reponse');

  if (estCorrect) {
    champReponse.textContent = "✅ Bien joué, c'est la bonne réponse !";
    champReponse.style.color = "green";
    score += 1
  } else {
    const bonneReponse = conteneurQuestion.querySelector("input[onclick*='true']").parentElement.textContent.trim();
    champReponse.textContent = `❌ Mauvaise réponse ! La bonne réponse est : ${bonneReponse}`;
    champReponse.style.color = "red";
  }

  champReponse.style.display = "block";

  // Désactiver toutes les options de réponse pour éviter de cliquer plusieurs fois
  const toutesLesOptions = conteneurQuestion.querySelectorAll('input[type="radio"]');
  toutesLesOptions.forEach(option => option.disabled = true);
}

function main(){
    verifier();
}