const bonIndex = Math.floor(Math.random() * 3);// permet de ne jamais avoir la bonne reponse est d'avoir un air un peu aleatoire //
let dejaJoue = false;

function choisirFiole(index) {
  const resultat = document.getElementById("resultat");

  if (dejaJoue) return;

  if (index === bonIndex) {
    resultat.textContent = "🎉 Tu as bu la potion magique ! Pouvoirs +100 !";
    resultat.style.color = "green";
  } else {
    resultat.textContent = "☠️ Oups... poison ! La bonne fiole était la numéro " + (bonIndex + 1);
    resultat.style.color = "red";
  }

  dejaJoue = true;
}
 function main(){
    choisirFiole();
 }