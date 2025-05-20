package interface2;

public class Realization.java implements Playable{

    @Override
    public void stop(){
    System.out.println("AUDIO STOP");
    }
    @Override
    public void play(){
    System.out.println("AUDIO PLAY");
    }
    @Override
    public void pause(){
    System.out.println("AUDIO PAUSE");
    }

}

