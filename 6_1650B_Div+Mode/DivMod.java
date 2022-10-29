import java.io.DataInputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.File;
import java.io.PrintWriter;

public class DivMod {
    public static void main(String[] args) throws IOException {
        SuperReader scr = new SuperReader("input#0.txt");
        PrintWriter out = new PrintWriter(System.out);
        
        int t = scr.nextInt();
        int l, r, a, x, result;
        for(int i=0; i<t; i++){
            l = scr.nextInt();
            r = scr.nextInt();
            a = scr.nextInt();
            x = r - ((r % a) + 1);
            if(x < l){x = r;}
            result = (x / a) + (x % a);
            out.println(result);
        }
        
        out.close();
        scr.close();
    }
}

class SuperReader{
    final private int bufSize = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;

    SuperReader(){
        din = new DataInputStream(System.in);
        buffer = new byte[bufSize];
        bufferPointer = 0;
        bytesRead = 0;
    }

    SuperReader(String fPath) throws FileNotFoundException{
        din = new DataInputStream(new FileInputStream(new File(fPath)));
        buffer = new byte[bufSize];
        bufferPointer = 0;
        bytesRead = 0;
    }

    public String next() throws IOException{
        byte[] s = new byte[100001];
        int c, cnt = 0;
        while((c = read()) != -1){
            if (c == ' ' || c == '\n' || c == 13){
                if(cnt != 0){
                    break;
                }else{
                    continue;
                }
            }
            s[cnt++] = (byte) c;
        }
        return new String(s, 0, cnt);
    }

    public String nextLine() throws IOException{
        byte[] s = new byte[1000001];
        int c, cnt=0;
        while((c = read()) != -1 && c != '\n' && c != 13){
            s[cnt++] = (byte) c;
        }
        return new String(s, 0, cnt);
    }

    public int nextInt() throws IOException{
        int c;
        int num = 0;
        boolean neg = ((c = read()) == '-');
        if(neg){
            c = read();
        }
        while(c != ' ' && c != '\n' && c != -1){
            if(c >= '0' && c <= '9'){
                num = num * 10 + (c - '0');
            }
            c = read();
        }
        return (neg)?-num:num;
    }

    public long nextLong() throws IOException{
        int c;
        long num = 0;
        boolean neg = ((c = read()) == '-');
        if(neg){
            c = read();
        }
        while(c == ' ' || c == '\n' || c == -1){
            if(c >= '0' && c <= '9'){
                num = num * 10 + (c - '0');
            }
            c = read();
        }
        return (neg)?-num:num;
    }

    private void fillBuffer() throws IOException{
        bytesRead = din.read(buffer);
        if(bytesRead == -1){
            buffer[0] = -1;
        }
    }

    private int read() throws IOException{
        if(bufferPointer == bytesRead){
            fillBuffer();
            bufferPointer = 0;
        }
        return (int) buffer[bufferPointer++];
    }

    public void close() throws IOException{
        if(din == null){
            return;
        }
        din.close();
    }
}


