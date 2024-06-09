import tkinter as tk
from tkinter import ttk, messagebox

# Morse code tables
morse_table = {
    'A': ".-", 'a': ".-",
    'B': "-...", 'b': "-...",
    'C': "-.-.", 'c': "-.-.",
    'D': "-..", 'd': "-..",
    'E': ".", 'e': ".",
    'F': "..-.", 'f': "..-.",
    'G': "--.", 'g': "--.",
    'H': "....", 'h': "....",
    'I': "..", 'i': "..",
    'J': ".---", 'j': ".---",
    'K': "-.-", 'k': "-.-",
    'L': ".-..", 'l': ".-..",
    'M': "--", 'm': "--",
    'N': "-.", 'n': "-.",
    'O': "---", 'o': "---",
    'P': ".--.", 'p': ".--.",
    'Q': "--.-", 'q': "--.-",
    'R': ".-.", 'r': ".-.",
    'S': "...", 's': "...",
    'T': "-", 't': "-",
    'U': "..-", 'u': "..-",
    'V': "...-", 'v': "...-",
    'W': ".--", 'w': ".--",
    'X': "-..-", 'x': "-..-",
    'Y': "-.--", 'y': "-.--",
    'Z': "--..", 'z': "--..",
    '0': "-----", '1': ".----",
    '2': "..---", '3': "...--",
    '4': "....-", '5': ".....",
    '6': "-....", '7': "--...",
    '8': "---..", '9': "----.",
    ' ': " ", ',': "--..--",
    '.': ".-.-.-", '?': "..--..",
    '-': "-....-", '/': "-..-.",
    '(': "-.--.", ')': "-.--.-",
    '&': ".-...", ':': "---...",
    ';': "-.-.-.", '=': "-...-",
    '+': ".-.-.", '_': "..--.-",
    '"': ".-..-.", '$': "...-..-",
    '@': ".--.-.", '!': "-.-.--"
}

reverse_morse_table = {v: k for k, v in morse_table.items()}

# Convert text to Morse code
def text_to_morse(text):
    output = ""
    for char in text:
        if char in morse_table:
            output += morse_table[char] + " "
        else:
            output += "? "  # Placeholder for unsupported characters
    return output.strip()

# Convert Morse code to text
def morse_to_text(morse):
    output = ""
    tokens = morse.split(" ")
    for token in tokens:
        if token in reverse_morse_table:
            output += reverse_morse_table[token]
        else:
            output += '?'  # Placeholder for unsupported Morse code
    return output

# Function to handle conversion based on the mode
def convert():
    text = input_text.get("1.0", "end-1c")
    mode = mode_var.get()
    if mode == 'text_to_morse':
        result = text_to_morse(text)
    elif mode == 'morse_to_text':
        result = morse_to_text(text)
    else:
        result = "Invalid mode selected."
    output_text.config(state=tk.NORMAL)
    output_text.delete("1.0", tk.END)
    output_text.insert(tk.END, result)
    output_text.config(state=tk.DISABLED)

# Initialize main window
root = tk.Tk()
root.title("Morse Code Converter")

# Mode selection
mode_var = tk.StringVar(value="text_to_morse")

frame = ttk.Frame(root, padding="10")
frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

ttk.Label(frame, text="Enter Text or Morse Code:").grid(row=0, column=0, columnspan=2, pady=(0, 5))

input_text = tk.Text(frame, height=5, width=50)
input_text.grid(row=1, column=0, columnspan=2, pady=(0, 10))

ttk.Radiobutton(frame, text="Text to Morse", variable=mode_var, value="text_to_morse").grid(row=2, column=0, sticky=tk.W)
ttk.Radiobutton(frame, text="Morse to Text", variable=mode_var, value="morse_to_text").grid(row=2, column=1, sticky=tk.W)

ttk.Button(frame, text="Convert", command=convert).grid(row=3, column=0, columnspan=2, pady=(10, 5))

ttk.Label(frame, text="Converted Output:").grid(row=4, column=0, columnspan=2, pady=(5, 5))

output_text = tk.Text(frame, height=5, width=50, state=tk.DISABLED)
output_text.grid(row=5, column=0, columnspan=2, pady=(0, 10))

# Run the application
root.mainloop()
