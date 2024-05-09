from datetime import date,datetime
import webbrowser
import time

responses = {
    "a": "Hi there!",
    "b": "Hello!",
    "date":str(date.today()),
	#"time":str(time.strftime("%H:%M:%S",time.localtime())),
    "time": str(datetime.now().strftime("%H:%M:%S")),
    "open web": "https://youtube.com/"
}

print("Bot: Hi! I'm here to assist you. Type 'bye' to exit.")

while True:
    x = input("You: ").lower()
    if x == "bye":
        print("Bot: Goodbye!")
        break
    response = responses.get(x, "Bot: Sorry, I don't understand.")
    
    if isinstance(response, str):
        print("Bot:", response)
    else:
        webbrowser.open(response)
