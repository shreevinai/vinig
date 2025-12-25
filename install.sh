#!/usr/bin/env bash

set -e

INSTALL_DIR="$HOME/.vinig"

echo "Installing Vinig..."

if [ -d "$INSTALL_DIR" ]; then
  echo "Vinig already installed at $INSTALL_DIR"
  exit 0
fi

git clone https://github.com/shreevinai/vinig.git "$INSTALL_DIR"

chmod +x "$INSTALL_DIR/bin/vg"

echo 'export PATH="$PATH:$HOME/.vinig/bin"' >> ~/.bashrc
echo 'export PATH="$PATH:$HOME/.vinig/bin"' >> ~/.zshrc

echo ""
echo "Vinig installed successfully!"
echo "Restart terminal and run: vg"
