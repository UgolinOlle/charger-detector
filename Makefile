# -- Variables
TARGET          = charger_detector
SRC_DIR         = srcs
INCLUDE_DIR     = includes
SOUNDS_NAME     = click.wav
SOUNDS_FILE     = assets/click.wav
SERVICE_FILE    = assets/charger-detector.service
SERVICE_DIR     = ~/.config/systemd/user/
SRC             = $(SRC_DIR)/main.c
CC              = gcc
CFLAGS          = -Wall -Wextra -O2 -I$(INCLUDE_DIR)

all: $(TARGET)

$(TARGET): $(SRC) $(INCLUDE_DIR)/charger.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

re: clean all

install: $(TARGET)
	@echo "Installation de $(TARGET) dans /usr/local/bin"
	sudo cp $(TARGET) /usr/local/bin/
	@echo "Installation du service $(SERVICE_FILE) dans $(SERVICE_DIR)"
	sudo mkdir -p $(SERVICE_DIR)
	cp $(SERVICE_FILE) $(SERVICE_DIR)
	@echo "Installation du son"
	sudo mkdir -p ~/Music/charger-detector && sudo cp $(SOUNDS_FILE) ~/Music/charger-detector/$(SOUNDS_NAME)
	@echo "Rechargement de systemd (service utilisateur)"
	systemctl --user daemon-reload
	@echo "Activation du service $(SERVICE_FILE)"
	systemctl --user enable charger-detector.service
	@echo "Démarrage du service $(SERVICE_FILE)"
	systemctl --user start charger-detector.service

uninstall:
	@echo "Arrêt du service $(SERVICE_FILE)"
	systemctl --user stop charger-detector.service
	@echo "Désactivation du service $(SERVICE_FILE)"
	systemctl --user disable charger-detector.service
	@echo "Suppression de $(TARGET) de /usr/local/bin"
	sudo rm -f /usr/local/bin/$(TARGET)
	@echo "Suppression du son $(SOUNDS_NAME)"
	sudo rm -rf ~/Music/charger-detector/$(SOUNDS_NAME)
	@echo "Suppression du service $(SERVICE_FILE) de $(SERVICE_DIR)"
	sudo rm -f $(SERVICE_DIR)$(SERVICE_FILE)
	@echo "Rechargement de systemd (service utilisateur)"
	systemctl --user daemon-reload

.PHONY: all re clean install uninstall

