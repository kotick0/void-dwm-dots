-- SETUPS

-- NvimTree
require("nvim-tree").setup()

-- Alpha startup screen / dashboard
require("alpha").setup(require("alpha.themes.startify").config)
require("alpha.themes.dashboard").section.footer.val = require("alpha.fortune")() -- Quotes

-- Theme
require("catppuccin").setup({
    integrations = {
        ts_rainbow = true,
    },
    color_overrides = {
        mocha = {
            text = "#F4CDE9",
            subtext1 = "#DEBAD4",
            subtext0 = "#C8A6BE",
            overlay2 = "#B293A8",
            overlay1 = "#9C7F92",
            overlay0 = "#866C7D",
            surface2 = "#705867",
            surface1 = "#5A4551",
            surface0 = "#44313B",

            base = "#352939",
            mantle = "#211924",
            crust = "#1a1016",
        },
    },
})
vim.cmd.colorscheme "catppuccin"

-- Lualine status bar
require("lualine").setup({
    options = {
        theme = "catppuccin",
        component_separators = " ",
        section_separators = { left = "", right = "" },
    },
})

-- Nvim Autopairs
require("nvim-autopairs").setup()

-- Git signs
require("gitsigns").setup()

-- Line highlighting
require("ibl").setup({
    indent = { char = "┊" },
    scope = { enabled = false },
})

-- Hex color highlighting
require("colorizer").setup()
