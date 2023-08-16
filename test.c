#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum, siginfo_t *info, void *context) {
    printf("Signal reçu : %d\n", signum);
    
    // Utilisation des informations supplémentaires dans siginfo_t
    printf("Code de si_code : %d\n", info->si_code);
    // Affichez d'autres champs de siginfo_t selon vos besoins

    // Vous pouvez également accéder à l'adresse où le signal s'est produit
    // sur certaines plates-formes (ne fonctionne pas partout)
    printf("Adresse de la faute : %p\n", info->si_addr);
}

int main() {
    struct sigaction sa;
    
    sa.sa_flags = SA_SIGINFO; // Indique l'utilisation de sa_sigaction au lieu de sa_handler
    sa.sa_sigaction = handler; // Pointeur vers la fonction de gestion du signal avec siginfo_t
    
    sigfillset(&sa.sa_mask);

    // Installation du gestionnaire de signal pour SIGSEGV (erreur de segmentation)
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    
    // Création d'une erreur de segmentation volontaire pour tester le gestionnaire
    int *ptr = NULL;
    *ptr = 42; // Cela devrait déclencher une erreur de segmentation

    return 0;
}
