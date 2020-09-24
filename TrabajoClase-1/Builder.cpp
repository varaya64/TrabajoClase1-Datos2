#include <iostream>

using namespace std;


class Pet{
    public:
    std::vector<std::string> parts_;
    void ListParts()const{
        std::cout << "Product parts: ";
        for (size_t i=0;i<parts_.size();i++){
            if(parts_[i]== parts_.back()){
                std::cout << parts_[i];
            }else{
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n"; 
    }
};

class petBuilder{
    public:
    virtual ~petBuilder(){}
    virtual void produceWings() const =0;
    virtual void produceClaws() const =0;
    virtual void produceFangs() const =0;
};

class petBuilder1 : public petBuilder{
    private:

    Pet* pet;

    /**
     * A fresh builder instance should contain a blank product object, which is
     * used in further assembly.
     */
    public:

    petBuilder1(){
        this->Reset();
    }

    ~petBuilder1(){
        delete pet;
    }

    void Reset(){
        this->pet = new Pet();
    }
    
    void produceWings()const override{
        this->pet->parts_.push_back("Alas");
    }

    void produceClaws()const override{
        this->pet->parts_.push_back("Garras");
    }

    void produceFangs()const override{
        this->pet->parts_.push_back("Colmillos");
    }

    Pet* getPet() {
        Pet* result= this->pet;
        this->Reset();
        return result;
    }
};


class Director{

    private:
    petBuilder* builder;

    public:

    void setPetbuilder(petBuilder* builder){
        this->builder=builder;
    }

    void buildJustClaws(){
        this->builder->produceClaws();
    }
    
    void BuildFullPet(){
        this->builder->produceClaws();
        this->builder->produceFangs();
        this->builder->produceWings();
    }
};

void ClientCode(Director& director)
{
    petBuilder* petBuilder = new petBuilder1();
    director.setPetbuilder(petBuilder);
    std::cout << "Mascota solo con garras\n"; 
    director.buildJustClaws();
    
    Pet* pet = petBuilder->getPet();
    pet->ListParts();
    delete p;

    std::cout << "Mascota con garras, alas y colmillos\n"; 
    director.BuildFullPet();

    p= petBuilder1->getPet();
    pet->ListParts();
    delete pet;

    std::cout << "Custom pet:\n";
    petBuilder->produceWings();
    petBuilder->produceFangs();
    pet=petBuilder1->getPet();
    pet->ListParts();
    delete pet;

    delete petBuilder;
}

