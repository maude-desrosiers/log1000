#include "RabaisTest.h"

// Librairies CppUnit nécessaires
#include <cppunit/ui/text/TestRunner.h>

int main() {
    // Crée un objet pour exécuter les tests.
    // Va résenter les résultats sous forme textuelle.
    CppUnit::TextUi::TestRunner runner;

    // La classe DiviseurTest contient des macros. 
    // Ces macros définissent une suite de tests.
    // Cela lui donne la méthode statique "suite" qui est appelée ici.
    // Cette méthode statique retourne des pointeurs vers les méthodes de tests.
    runner.addTest(RabaisTest::suite());
    


    // Exécute les tests et affiche les résultats.
    runner.run();

    return 0;
}