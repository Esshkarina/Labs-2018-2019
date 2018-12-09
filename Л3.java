//это супер класс, в который входят три подкласса Cat, Dog, Parrot
 
class Animal {
    // сдесь задаем одинаковые типы данных для всех животных, индивидуальные навыки(типы данных) задаются в классе для конкретного животного
 
    public String name;
    public int run;
 
    public Animal() {
    }
 
    public Animal(String name) {
        this.name = name;
    }
 
    public void animalInfo() {
        System.out.println();
 
    }
}
 
//это подкласс Cat, супер класса Animal с наследованием extends
class Cat extends Animal {

 protected boolean sweem;
 protected boolean sayWords;
 int jump;

//konstruktor Cat

  public Cat(String name, int run, boolean sweem, int jump, boolean sayWords) {
	  this.name = name;
      this.run = run;
      this.sweem = sweem;
      this.jump = jump;
      this.sayWords = sayWords;
  }

  public void catInfo() {
      System.out.println("CatName: " + name + " /RunLimit: " + run+ " meters/" + " /Sweem:" + sweem + " /Jump: " +jump+ " meters/" + "/SayLimit:" + sayWords + " words/");
  }
}

//это подкласс Parrot, супер класса Animal с наследованием extends
class Parrot extends Animal {

 protected boolean sweem;
 protected boolean run;
 int sayWords;
 int jump;
//konstruktor Parrot

  public Parrot (String name, boolean run, boolean sweem, int jump, int sayWords) {
      this.name = name;
      this.run = run;
      this.sweem = sweem;
      this.jump = jump;
      this.sayWords = sayWords;
  }

  public void parrotInfo() {
      System.out.println("ParrotName: " + name + " /RunLimit: " + run+ " meters/" + " /Sweem:" + sweem + " /Jump: " +jump+ " meters/" + "/SayLimit:" + sayWords + " words/");
  }
}

//это подкласс Dog супер класса Animal с наследованием extends
class Dog extends Animal {
	protected boolean sayWords;
    public double jump;
    public int sweem;
 
        //konstruktor Dog
 
        public Dog(String name, int run, int sweem, double jump, boolean sayWords ) {
            this.name = name;
            this.run = run;
            this.sweem = sweem;
            this.jump = jump;
            this.sayWords = sayWords;
        }
        public void dogInfo() {
            System.out.println("DogName: " + name  + " /RunLimit: " + run+ " meters/" + " /Sweem:" + sweem + " /Jump: " +jump+ " meters/" + "/SayLimit:" + sayWords + " words/");
        }
    }
 
public class Main {
    public static void main(String[] args) {
 
        Animal animal = new Animal("CatsCategory");
        Cat cat = new Cat("Barsik", 200, false, 2, false);
        animal.animalInfo();
        cat.animalInfo();
        cat.catInfo();
 
        Animal panimal = new Animal("Parrot");
        Parrot parrot = new Parrot("Kesha", false, false, 0, 365);
        panimal.animalInfo();
        parrot.animalInfo();
        parrot.parrotInfo();
        
        Animal danimal = new Animal("Dogs");
        Dog dog = new Dog("Sharik", 500, 10, 0.5, false);
        danimal.animalInfo();
        dog.animalInfo();
        dog.dogInfo();
 
   }
}
