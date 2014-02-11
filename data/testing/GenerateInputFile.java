import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class GenerateInputFile {
		
	private static final String FILENAME = "InputFile";
	private static int NUM_ADDRESSES = 20;
	private static int SEED = 9632901;
			
	public static void main(String[] args) {
	
		if(args.length > 1){
			NUM_ADDRESSES = Integer.parseInt(args[1]);
		}
		
		Random rand = new Random(SEED);
		try {
			long addressSpace = (long)Math.pow(2, 16);
			BufferedWriter writer = new BufferedWriter(new FileWriter(FILENAME + "_" + NUM_ADDRESSES + ".txt"));
			for(int i=0; i<NUM_ADDRESSES; i++){
				
				long randNum = Math.abs(rand.nextLong()); //i
				long address = randNum % addressSpace;
				System.out.println(address);
				writer.write(address + "\n");
			}
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}
}
