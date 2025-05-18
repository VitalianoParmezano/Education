package interface_pac;

public class CashPay implements PayInterface {

    @Override
    public void pay(int a){
        System.out.println("Cash pay: "+ a + " money");
    }

}
