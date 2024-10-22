


#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();


    // const Animal* copy = meta;//stex chi kanchvum copy ctor,uxxaki copy-n ira mej pahuma metai hascen,dra hamar vor delete enq anum copy-n sef faulta qcum,vortev verjum mihate delete meta enq grum,inchy beruma double free-i
    // std::cout << "meta &->" <<meta<< std::endl;
    // std::cout << "copy-i mejini hascen->" <<copy<< std::endl;
    ////////////////////////////////////////////////////
    // std::cout << "meta &->" <<meta<< std::endl;
    // std::cout << "copy-i hascen->" <<&copy<< std::endl;
    //////////////////////////////////////////////////
    // delete copy;

           ///////////////////////////////
        //    const Animal copy =* meta;//copy ctori kanch(copy-i cucichy stackuma)
           ////////////////////////////

    // const Animal* copy = new Animal(*meta);//copy ctori kanch(copy-i cucichy heapuma)
    // std::cout << "meta &->" <<meta<< std::endl;
    // std::cout << "copy-i mejini hascen->" <<copy<< std::endl;
    // delete copy;



    // const Cat* i = new Cat();
    // const Animal* copy_cat = new Cat(i);
    // (void)copy_cat;
    // delete copy_cat;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return 0;
}

// int main()
// {
//     const WrongAnimal* meta = new WrongAnimal();
//     // const WrongAnimal* j = new Dog();
//     const WrongAnimal* i = new WrongCat();

//     // std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     // j->makeSound();
//     meta->makeSound();
//     delete meta;
//     // delete j;
//     delete i;
//     return 0;
// }