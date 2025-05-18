package interface_pac;

public class CardPay implements PayInterface {

    @Override
    public void pay(int a){
        System.out.println("CarD pay: "+ a + " money");
    }

}
