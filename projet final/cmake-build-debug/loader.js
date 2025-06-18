
function jaipas2noms() {
  document.querySelector(".loader-container").classList.add('Hidden'); // viens crée une balise hidden apres 3s quand la balise apparait le css avec pour balise hidden chargera 
}
setTimeout(jaipas2noms, 3000); // le loader dure 3s
function main(){
    jaipas2noms();
}