import serial
from time import sleep
from openai import OpenAI

client = OpenAI(api_key="YOUR_TOKEN") 
ser = serial.Serial("COM14", 9600)
sleep(2) 

while True:

    line = ser.readline().decode('utf-8').strip()
    print("Arduino says:", line)

    response = client.chat.completions.create(
        model="gpt-3.5-turbo",
        messages=[
            {"role": "user", "content": f"This is today's temperature {line}, what should I wear?"},
        ]
    )
    
    advice = response.choices[0].message.content
    print("Advice from AI:", advice)
    
    ser.write(advice.encode('utf-8'))
    sleep(1)