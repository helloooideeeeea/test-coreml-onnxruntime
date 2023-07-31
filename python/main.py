import torch.nn as nn
import torch.onnx


class LargeModel(nn.Module):
    def __init__(self):
        super(LargeModel, self).__init__()
        self.block1 = nn.Sequential(
            nn.Linear(16000, 10000),
            nn.ReLU()
        )
        self.block2 = nn.Sequential(
            nn.Linear(10000, 10000),
            nn.ReLU()
        )
        self.block3 = nn.Sequential(
            nn.Linear(10000, 10000),
            nn.ReLU()
        )
        self.block4 = nn.Sequential(
            nn.Linear(10000, 10000),
            nn.ReLU()
        )
        self.fc = nn.Linear(10000, 16000)

    def forward(self, x):
        x = self.block1(x)
        x = self.block2(x)
        x = self.block3(x)
        x = self.block4(x)
        x = self.fc(x)
        return x

model = LargeModel()

# Print the total number of parameters
total_params = sum(p.numel() for p in model.parameters())
print(f'Total number of parameters: {total_params}')

x = torch.randn(1, 16000)

torch.onnx.export(model, x, "../large_model.onnx", input_names=["input"], output_names=["output"])