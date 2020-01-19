#include "RabaisTest.h"
#include <cmath> //necessaire


void RabaisTest::setUp() {
    this->rabais_a_tester = new Rabais("data/clients.dat");
}

void RabaisTest::tearDown() {
    delete this->rabais_a_tester;
}

void RabaisTest::test_quelconque() {
    int i = 1;
	CPPUNIT_ASSERT_EQUAL(1, i);
}

//Correspond à d1 = <{f, 10456}, {0.07}>
//f est une facture qui s eleve a une montant de 165.30$
void RabaisTest::d1() {
    Facture une_facture;
	une_facture.ajouterItem(50.95);
	une_facture.ajouterItem(48.95);
	une_facture.ajouterItem(25.45);
	une_facture.ajouterItem(39.95);

    float rabais1 = this->rabais_a_tester->getRabais(une_facture, 10456);

	CPPUNIT_ASSERT_EQUAL(float(0.07), rabais1);
}

// Correspond à d2 = <{f, 14770}, {0.17}>
// f est une facture avec un item initalise a 120$
void RabaisTest::d2() {
    Facture f = Facture();
    f.ajouterItem(120);
    float rabais1 = this->rabais_a_tester->getRabais(f, 14770);

	CPPUNIT_ASSERT_EQUAL(float(0.17), rabais1);
}

// Correspond à d3 = <{f, 15034}, {0.09}>
// f est une facture avec un item initalise a 840$
void RabaisTest::d3() {
    Facture f = Facture();
    f.ajouterItem(840);
    float rabais1 = this->rabais_a_tester->getRabais(f, 15034);

	CPPUNIT_ASSERT_EQUAL(float(0.09), rabais1);
}

// Correspond à d4 = <{f, 25102}, {0.15}>
void RabaisTest::d4() {
    Facture f = Facture();
    float rabais1 = this->rabais_a_tester->getRabais(f, 25102);

	CPPUNIT_ASSERT_EQUAL(float(0.15), rabais1);
}

// Correspond à d5 = <{f, 11111}, {0.22}>
//client ajoute 11111 Boquet Bill 99 J4O 1980-12-01
void RabaisTest::d5() {
    Facture f = Facture();

    float rabais1 = this->rabais_a_tester->getRabais(f, 11111);

	CPPUNIT_ASSERT_EQUAL(float(0.22), rabais1);
}
