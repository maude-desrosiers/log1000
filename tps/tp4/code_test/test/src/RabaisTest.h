#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>           
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TextTestRunner.h>

//fichier a tester
#include "../../src/rabais.h"

class RabaisTest : public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(RabaisTest);
    CPPUNIT_TEST(test_quelconque);
    CPPUNIT_TEST(d1);
    CPPUNIT_TEST(d2);
    CPPUNIT_TEST(d3);
    CPPUNIT_TEST(d4);
    CPPUNIT_TEST(d5);
    CPPUNIT_TEST_SUITE_END();
private:
    Rabais* rabais_a_tester;
public:
    //fonction d'echafaudage
    void setUp();
    void tearDown();

    //Fonction de tests
    void test_quelconque();
    void d1();
    void d2();
    void d3();
    void d4();
    void d5();
};

